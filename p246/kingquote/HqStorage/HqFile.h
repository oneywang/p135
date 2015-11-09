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
	asio::io_service ioqueue;//io����
	HqCfg param;

	//��ʵֻ��������ҵ 
	HqLifeCycle _hq_infi;

	//�رյ�ǰ�ļ�
	void close_current_file();
	void load_exist_files();
	bool load_cfg(pugi::xml_node &nodecfg);

public:
	void handle_timer(const asio::error_code& e);
};

