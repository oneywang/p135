#pragma once

namespace pugi
{
	class xml_node;
}

//�г��Ķ����ļ�
struct SubMarketTime
{
	SubMarketTime()
	{
		_open = _close = -1;
	}
	int16_t	_open;	// ǰ����ʱ��
	int16_t	_close;	// ǰ����ʱ��
	int16_t   dist() { return (_close - _open); }
	//����ƫ����
	void suboffset(int offset)
	{
		//ΪʲôҪ�������
		offset /= 60;
		if (_open >= offset)
		{
			_open -= offset;
			_close -= offset;
			if (_open >= 24 * 60)
			{
				_open = _open - 24 * 60;
				_close = _close - 24 * 60;
			}
			return;
		}
		_open = _open + 24 * 60 - offset;
		_close = _close + 24 * 60 - offset;
		if (_open >= 24 * 60)
		{
			_open = _open - 24 * 60;
			_close = _close - 24 * 60;
		}
	}
};

class SubMarketDef
{
public:
	SubMarketDef()
	{
		_codetype = 0;
		_client_price_unit = 0;
		_send_price_unit = 0;
		_lClientDecimal = 0;
	}
	uint32_t _codetype;//���г�
	std::string	_name;//��Ʊ����	
	std::vector<std::string> _codescope;//�����Ĺ�Ʊ
	std::string	_str_notcode;  // �������Ĵ���
	std::vector<SubMarketTime> _mts;

	long _client_price_unit;
	long _send_price_unit;
	long _lClientDecimal;
};

//�����ǿ�������json����xml
//�����Ƕ�ȡ�������г������г�ID,ʱ������֮��Ķ���!!!
class HqCfg
{
public:
	HqCfg();
	~HqCfg();

	std::vector<SubMarketDef> _submarketdefs;
	SubMarketDef _submarketfasts[16];
	std::string _shortname;//�����ƣ��� �Ϻ�֤ȯ

	uint16_t _hsid;

	uint32_t _max_mincount;//����������
	uint32_t _max_stockcount;//��Ʊ�����

	double _stk_volume_multi;//�����ĵ�λ
	double _stk_money_multi;
	double _stk_qhmoney_multi;

	float _stk_hand;//����

	double _stk_minunit;

	bool _has_vol;
	bool _has_money;

	bool _has_avgprice;//�Ƿ��о���


	//��һ����Ϊ�����գ�

	//�Ƿ�ʹ��stk��Ŀ��̣���ߣ���ͣ�����
	bool _use_stk_open;
	bool _use_stk_high;
	bool _use_stk_low;
	bool _use_stk_preclose;

	bool _check_dup;//����Ƿ��ظ���
	bool _userrpttime;//�Ƿ�ʹ���г�ʱ��

	std::vector<SubMarketTime> _mts;

	bool load_cfg(pugi::xml_node &nodecfg);

	uint16_t get_type_by_code(const std::string &strCode);
};

