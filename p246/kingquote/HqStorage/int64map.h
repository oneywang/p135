#pragma once
#include <unordered_map>
#include <stdint.h>

//���Ǽ���key�ĳ��������6������������û��һ��uint64����
class KingInt64ToIntMap
{
public:
	std::unordered_map<uint64_t,int> m_mapPosition;

	bool  InitMap(int nHashTableSize=0)
	{
		DeleteMap();
		return true;
	}

	bool  InitMap_Raw(int nHashTableSize=0)
	{
		return InitMap(nHashTableSize);
	}

	bool  AddToMap(uint64_t key,int position)
	{
		m_mapPosition[key]=position;
		return true;
	}

	bool AddToMap(uint16_t mktid,const char *symbol,int posotion)
	{
		uint64_t curkey = KeyToInt64(symbol, mktid);
		return AddToMap(curkey, posotion);
	}

	int GetPosition(uint16_t mktid, const char *symbol)
	{
		uint64_t curkey = KeyToInt64(symbol, mktid);
		return GetStockByMap(curkey);
	}

	bool  DeleteFromMap(uint64_t lKey)
	{
		std::unordered_map<uint64_t, int>::iterator it = m_mapPosition.find(lKey);
		if(it==m_mapPosition.end())
			return false;
		m_mapPosition.erase(it);
		return true;
	}

	void  DeleteMap()
	{
		m_mapPosition.clear();
	}


	int GetStockByMap(uint64_t key)
	{
		std::unordered_map<uint64_t,int>::iterator it=m_mapPosition.find(key);
		if(it==m_mapPosition.end())
			return -1;
		return it->second;
	}

	

public:

	static uint64_t KeyToInt64(const char *key,int16_t mkt)
	{
		uint64_t result=0;
		char *presult=(char *)&result;
		strncpy(presult+2,key,6);
		//������û����λ�ģ�Ӧ��û���ˣ�����2a01���ж�һ��Ҳû�¡�
		if(presult[7]==' ')
		{
			presult[7]=0;
			if (presult[6] == ' ')
			{
				presult[6] = 0;
				if (presult[5] == ' ')
				{
					presult[5] = 0;
				}
			}
		}
		presult[0] = mkt % 256;
		presult[1] = mkt / 256;
		return result;
	}
};