#pragma once
#include <stdint.h>
//�������ض���
#pragma warning(disable:4200)

//�������룬�����п��ܻ�������
#pragma pack(push,4)

//һ����Ʊ���ܻ���4800��!!!
class HqTick
{
public:
	//tick����
	int32_t upttime;//ʱ�䣬ʱ���ʽΪ���������*10+΢�루����һ�����ж���ƹ���)���������ϲ�������һ�볬��10�ʵ�
	int32_t px;//�۸�
	int32_t vol;//�ɽ���
	float money;//�ɽ����
	int32_t position;//�ֲ���
	int32_t cjbs;//�ɽ�����
};
//���������ļ���һ�����ķ����!!!�ȷ����д!!!��������4800,����һ���Է���1024
class HqTickBlock
{
public:
	int16_t curpos;//��ǰƫ����
	int16_t nextblock;//��һ����ƫ��
	int32_t nouse;//û���õ�
};

//ÿ����¼��Ϣ������һ��ͷ����Ϣ
class HqRecord
{
public:
	int16_t idx;//���
	int16_t mktid;//�г����,���ܻ������г���
	int32_t lasttime;//���ʱ�䣬�����Ǽ���1990��ʱ��
	char symbol[8];//ʵ����ֻ�õ�6
	char name[32];//ʵ����ֻ���õ�24
	int32_t preclosepx;//ǰ���̼�,���ڿ���ͳһ�����
	int32_t prejspx;//ǰ�����
	int32_t openpx;
	int32_t highpx;
	int32_t lowpx;
	int32_t newpx;//���̼ۣ���ʵ���и����¼ۣ����¼ۣ�=���̼�
	int32_t todayjspx;//������
	int32_t vol;//�ɽ���
	float money;//�ɽ����
	int32_t position;//�ֲ���
	int32_t cjbs;//�ɽ�����
};


class HqMinRecord
{
public:
	//����ķ�����
	uint32_t lasthqtime;//�������ʱ�䣬ȥ��1990��ʱ��
	int32_t openpx;
	int32_t highpx;
	int32_t lowpx;
	int32_t newpx;//���̼ۣ���ʵ���и����¼ۣ����¼ۣ�=���̼�
	int32_t vol;//�ɽ���
	float money;//�ɽ����
	int32_t position;//�ֲ���
	int32_t cjbs;//�ɽ�����
	int32_t nouse;//δʹ��
};


#define HQFILEITEMCOUNT 14336
//ͷ����Ϣ�������趨Ϊ
class HqFileHdr
{
public:
	int32_t dt;//��ǰ����
	int32_t count;//������
	int32_t mincount;//����������
	int32_t ticklastpos;//���һ��tick������
	HqRecord rtrec[HQFILEITEMCOUNT];
	HqMinRecord minrec[0];
	static int32_t get_hdr_size(int hqmincount)
	{
		int32_t strsize = sizeof(HqFileHdr);
		strsize += hqmincount*HQFILEITEMCOUNT*sizeof(HqMinRecord);
		return strsize;
	}
	HqMinRecord *get_min_rec_by_idx(int stkidx)
	{
		return &minrec[stkidx + mincount];
	}
	int64_t get_tickblock(int idx)
	{
		//ȡ�õ�N������ƫ����
		int64_t hdrsize = get_hdr_size(mincount);
		return hdrsize + idx*sizeof(HqTickBlock);
	}
};

#pragma pack(pop)
//10240+4096