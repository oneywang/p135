#include "stdafx.h"
#include "HqCfg.h"
#include "../base/hsmarketdef.h"
#include "../base/strutil.h"

HqCfg::HqCfg()
{
	_use_stk_open = true;
	_use_stk_high = true;
	_use_stk_low = true;

	_has_vol = true;
	_has_money = true;
	_has_avgprice = true;
	_check_dup = false;
	_userrpttime = true;
}


HqCfg::~HqCfg()
{
}

bool HqCfg::load_cfg(pugi::xml_node& nodecfg)
{

	return true;
}

uint16_t HqCfg::get_type_by_code(const std::string &strCode)
{
	short nTotal = 16;

	bool bStock = (_hsid == (STOCK_MARKET | SH_BOURSE) || _hsid == (STOCK_MARKET | SZ_BOURSE));
	if (bStock)
	{
		for (size_t i = 0; i < strCode.size(); i++)
		{
			//�������ж�1a01,2a01֮���ָ���õģ�ֻ��ָ������abcdef֮��ġ�
			if (isalpha(strCode[i]))
				return (_hsid | KIND_INDEX);
		}
	}
	int nLen = strCode.size();

	for (int i = 0; i < _submarketdefs.size(); i++)
	{
		SubMarketDef &submarket = _submarketdefs[i];

		for (int subindex = 0; subindex < submarket._codescope.size(); subindex++)
		{
			std::string &curscope = submarket._codescope[subindex];
			int nsep = curscope.find('~');
			if (nsep == std::string::npos)
			{
				if (StrUtil::startsWith(strCode, curscope, false))
					return (HSMarketDataType)submarket._codetype;
			}
			std::string firstscope = StrUtil::left(curscope, nsep);
			std::string secondscope = curscope.substr(nsep + 1);
			if ((strCode >= firstscope) && (strCode <= secondscope))
				return (HSMarketDataType)submarket._codetype;
		}
	}

	//������ǹ�Ʊ�Ļ�����ֱ�ӷ��أ����������������Ϊ���÷����ˡ�
	if (!bStock)
	{
		return 0;
	}
	if (_submarketfasts[15]._codetype != 0)
		return _hsid | SC_Others;
	return 0;
}
