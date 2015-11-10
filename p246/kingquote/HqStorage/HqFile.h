#pragma once
#include "../base/hqdef.h"
#include "int64map.h"
#include "MemMapFile.h"
#include "../base/BoostFile.h"
#include "../base/Stockdrv.h"
#include <asio/io_service.hpp>
#include "HqCfg.h"
#include "../base/dtz.h"
#include "HqLifeCycle.h"
#include "../base/basic_repeating_timer_asio.h"

namespace pugi
{
	class xml_node;
}

class HqFile
{
public:
	HqFile();
	~HqFile();
	static void set_default_dir(const std::string &rtdir, const std::string &datadir)
	{
		default_panhoudir = datadir;
		default_rtdir = rtdir;
	}

	KingInt64ToIntMap stk_map;//��Ʊ����!!!��Ȼ��hash��
	MemMapFile stk_file;//���ļ�
	HqFileHdr *stk_hdr;//�ļ�ͷ��
	BoostFile tick_file;//����ļ���ʼ���õ�


	std::string _name;
	uint32_t _hsid;
	int32_t _market_time_offset;
	_datetime_t _curtm;
	asio::repeating_timer* _loop_timer;

	std::string _rt_dir;
	std::string _panhou_dir;
	
	static std::string default_panhoudir;
	static std::string default_rtdir;

	void handle_rpt(RCV_REPORT_STRUCTEx *rpt);

	bool handle_stk_report_other_thread(std::vector<std::string> *newreports)
	{
		run_in_own_thread(boost::bind(&HqFile::handle_stk_report_in_thread, this, newreports));
		return true;
	}

	bool handle_stk_report_in_thread(std::vector<std::string> *newreports);

	asio::io_service ioqueue;//io����
	HqCfg param;

	//������ҵ�ͳ�ʼ��!!!
	HqLifeCycle _hq_infi;

	template <typename Handler>
	void run_in_own_thread(Handler handler)
	{
		ioqueue.post(handler);
	}

	//�رյ�ǰ�ļ�
	void close_current_file();
	void load_exist_files();
	bool load_cfg(pugi::xml_node &nodecfg);

	int find_or_add(const char *symbol, const char *name, int preclose);

public:
	void handle_timer(const asio::error_code& e);
};

