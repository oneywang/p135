#pragma once
#include <unordered_map>
#include "../base/hsmarketdef.h"

enum STKTYPE
{
	STK_JJQH=0,
	STK_WJF=1,
	STK_YJ=2,//����
};

class CodeMap
{
public:
	CodeMap()
	{
		init();
	}
	
	int transfer_code(uint16_t &market,char *label);
private:
	void init();

	//����ת��
	void transfer_sh_code(char *label);
	void transfer_sz_code(char *label);

	//���ص���1,2,3,4,5,0Ϊ��֪��������ֱ�Ӳ�����
	
	std::unordered_map<uint32_t,std::pair<uint16_t,const char *> > nq_code_map;//����ǹ����ڻ�
	std::unordered_map<uint16_t, uint16_t > wq_code_map;//����������ڻ�
	std::unordered_map<uint32_t, std::pair<uint16_t, std::string> > id_code_map;//�����ȫ��ָ��,

};