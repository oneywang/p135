#pragma once
#include "../base/hqdef.h"
#include "int64map.h"
#include "MemMapFile.h"
#include "BoostFile.h"
#include "Stockdrv.h"

class HqFile
{
public:
	HqFile();
	~HqFile();
	KingInt64ToIntMap stk_map;//��Ʊ����!!!��Ȼ��hash��
	MemMapFile stk_file;//���ļ�
	HqFileHdr *stk_hdr;//�ļ�ͷ��
	BoostFile tick_file;//����ļ���ʼ���õ�
	void handle_rpt(RCV_REPORT_STRUCTEx *rpt);
};

