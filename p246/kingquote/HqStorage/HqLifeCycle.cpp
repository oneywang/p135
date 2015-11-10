#include "stdafx.h"
#include "HqLifeCycle.h"
#include "HqFile.h"
#include "../base/pugixml.hpp"

HqLifeCycle::HqLifeCycle(HqFile &hf)
	:_storage(hf)
{
}


HqLifeCycle::~HqLifeCycle()
{
}

void HqLifeCycle::load_cfg(pugi::xml_node xml_nodes)
{
}

bool HqLifeCycle::need_init(_datetime_t &td)
{
	int curweek = td.day_of_week();
	if (curweek >= 1)
		curweek = curweek - 1;
	else
		curweek = 6;
	if (_init_week[curweek] == false)
		return false;
	if (_init_not_days.find(td.raw_date()) != _init_not_days.end())
		return false;
	return true;
}

void HqLifeCycle::on_localdt_changed(_datetime_t &ldt)
{
	_localdt = ldt;
	//����Ҫ�ж�,������Զ���ʼ��������
	if (_auto_infi)
	{
		//������Զ����̺ͳ�ʼ��
		//�����û�г�ʼ�������ߵ�ǰ�г���ʱ�䲻�ǵ�ǰ��ʱ�䣬�������̣�����
		//�����Ҫ�����ڻƽ����Ⱥ�Լ����̶����г���ֻҪ�����ھ�ִ�п�����ҵ ��
		if ((!_storage.is_valid()) || (_localdt.raw_date() != _storage.stk_hdr->dt))
		{
			//����Ҫ��ʼ������ҵ����������ʼ������������
			_storage.shoupan_market();//��������ҵ
			//�ٿ�ʼ��ʼ��������
			if (need_init(_localdt))
			{
				_storage.init_market(_localdt);
			}
			else
			{
				_storage.log("%s ����Ҫ��ʼ�� %d (auto infi)", _storage._name.c_str(), _localdt.raw_date());
			}
		}
	}
	else
	{
		int hour = _localdt.hour();
		int minute = _localdt.min();
		int temphm = hour * 100 + minute;
		//������黹û�г�ʼ�����������ڲ��ǵ�ǰ����
		if ((!_storage.is_valid()) || (_localdt.raw_date() != _storage.stk_hdr->dt))
		{

			if (temphm >= _init_time)
			{
				if (need_init(_localdt))
					_storage.init_market(_localdt);
				else
				{
					_storage.log("%s ����Ҫ��ʼ�� %d (non auto infi)", _storage._name.c_str(), _localdt.raw_date());
				}
			}
		}
		else if (temphm >= _shoupan_time)
		{
			_storage.shoupan_market();
		}
	}
}