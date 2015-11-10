#pragma once
#include "../base/dtz.h"
#include <set>

class HqFile;

namespace pugi
{
	class xml_node;
}

class HqLifeCycle
{
public:
	HqLifeCycle(HqFile &hf);
	~HqLifeCycle();
	void load_cfg(pugi::xml_node &curnode);
	void on_localdt_changed(_datetime_t &ldt);
	bool need_init(_datetime_t &td);

	HqFile &_storage;

	bool _auto_infi;
	bool _init_use_conf_symbols;//�Ƿ�ʹ�ù̶�����,xml�еĴ���,ȱʡ��false
	bool _init_week[7];//�����ܼ����п���,//0-�����գ�1������һ
	std::set<uint32_t> _init_not_days;//����Ҫ��ʼ��������
	std::vector<std::string> _init_symbols;//�̶����������

	_datetime_t _localdt;//�������ʱ�䣬������Ѿ����ƫ������ʱ���ˣ�����
	_datetime_t _hqdt;//����Դ���ʱ�䣬���Ҳ�����ƫ�����������ʱ���ˣ�����

	//����ƫ�������ʱ�䣬�������ģ�����
	uint32_t _init_time;//����˵�Ϻ��г�����093000,9���ӽ��г�ʼ��
	uint32_t _shoupan_time;//����˵�Ϻ��г�����153000,15������������ҵ����������̣����ܾ���235959
	int32_t _isprev;
};

