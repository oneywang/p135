#pragma once

/*
�г�����壺
��λ�����ʾ���£�
15		   12		8					0
|			|	  	  |					|
| ���ڷ���	|�г����� |	����Ʒ�ַ���	|
*/
typedef unsigned short HSMarketDataType;			  // �г�������������
/*���ڴ���*/
#define STOCK_MARKET			 0X1000   // ��Ʊ
#	define SH_BOURSE			 0x0100   // �Ϻ�
#	define SZ_BOURSE			 0x0200   // ����
#	define SYSBK_BOURSE			 0x0400   // ϵͳ���
#	define USERDEF_BOURSE		 0x0800   // �Զ��壨��ѡ�ɻ����Զ����飩
#			define KIND_INDEX		 0x0000   // ָ�� 
#			define KIND_STOCKA		 0x0001   // A�� 
#			define KIND_STOCKB		 0x0002   // B�� 
#			define KIND_BOND		 0x0003   // ծȯ
#			define KIND_FUND		 0x0004   // ����
#			define KIND_THREEBOAD	 0x0005   // ����
#			define KIND_SMALLSTOCK	 0x0006   // ��С�̹�
#			define KIND_PLACE		 0x0007	  // ����
#			define KIND_LOF			 0x0008	  // LOF
#			define KIND_ETF			 0x0009   // ETF
#			define KIND_QuanZhen	 0x000A   // Ȩ֤

#			define KIND_OtherIndex	 0x000E   // ������������࣬��:����ָ��

#			define SC_Others		 0x000F   // ���� 0x09
#			define KIND_USERDEFINE	 0x0010   // �Զ���ָ��


// �۹��г�
#define HK_MARKET				 0x2000 // �۹ɷ���
#	define HK_BOURSE			 0x0100 // �۹�
#	define	HK_OPTIONS			 0x0200 // ţ��֤


#	define SYSBK_BOURSE			 0x0400 // �۹ɰ��(H��ָ���ɷݹɣ�Ѷ�����ָ���ɷݹɣ���
#	define USERDEF_BOURSE		 0x0800 // �Զ��壨��ѡ�ɻ����Զ����飩
#			define HK_KIND_BOND		 0x0000   // ծȯ
#			define HK_KIND_MulFund	 0x0001   // һ�����Ϲ�֤
#			define HK_KIND_FUND		 0x0002   // ����
#			define KIND_WARRANTS	 0x0003   // �Ϲ�֤
#			define KIND_JR			 0x0004   // ����
#			define KIND_ZH			 0x0005   // �ۺ�
#			define KIND_DC			 0x0006   // �ز�
#			define KIND_LY			 0x0007   // ����
#			define KIND_GY			 0x0008   // ��ҵ
#			define KIND_GG			 0x0009   // ����
#			define KIND_QT			 0x000A   // ����

/*�ڻ�����*/
#define FUTURES_MARKET			 0x4000 // �ڻ�
#		define DALIAN_BOURSE		 0x0100	// ����
#		define SHANGHAI_BOURSE	  0x0200	// �Ϻ�
#		define ZHENGZHOU_BOURSE	  0x0300	// ֣��
#		define HUANGJIN_BOURSE	  0x0400		// �ƽ�����
#		define GUZHI_BOURSE		  0x0500		// ��ָ�ڻ�

#		define SELF_BOURSE		  0x0600	// �Զ�������
#		define DZGT_BOURSE		  0x0610	// ���ڸ�������
#		define DLTL_BOURSE		  0x0620	// ��������
#		define YSJS_BOURSE		  0x0630	// ��ɫ����

#		define DynamicSelf_BOURSE 0x0700	// ��̬���������Զ�������

/*���̴���*/
#define WP_MARKET				 (0x5000) // ����
#		define WP_INDEX				0x0100	// ����ָ�� // ������
#		define WP_LME				0x0200	// LME		// ������
#			define WP_LME_CLT			0x0210 //"����ͭ";
#			define WP_LME_CLL			0x0220 //"������";
#			define WP_LME_CLM			0x0230 //"������";
#			define WP_LME_CLQ			0x0240 //"����Ǧ";
#			define WP_LME_CLX			0x0250 //"����п";
#			define WP_LME_CWT			0x0260 //"������";
#			define WP_LME_CW			0x0270 //"����";
#			define WP_LME_SUB			0x0000

#			define WP_CBOT				0x0300	// CBOT			
#			define WP_NYMEX	 			0x0400	// NYMEX	 	
#			define WP_NYMEX_YY			0x0000	//"ԭ��";
#			define WP_NYMEX_RY			0x0001	//"ȼ��";
#			define WP_NYMEX_QY			0x0002	//"����";

#			define WP_COMEX	 			0x0500	// COMEX	 	
#			define WP_TOCOM	 			0x0600	// TOCOM	 	
#			define WP_IPE				0x0700	// IPE			
#			define WP_NYBOT				0x0800	// NYBOT		
#			define WP_NOBLE_METAL		0x0900	// �����	
#			  define WP_NOBLE_METAL_XH	0x0000  //"�ֻ�";
#			  define WP_NOBLE_METAL_HJ	0x0001  //"�ƽ�";
#			  define WP_NOBLE_METAL_BY	0x0002  //"����";

#			define WP_MY		0x0a00	// �������Ǵ�������
#			define WP_SICOM				0x0b00	// SICOM		
#			define WP_LIBOR				0x0c00	// LIBOR		
#			define WP_NYSE				0x0d00	// NYSE
#			define WP_CEC				0x0e00	// CEC


#			define WP_Other_TZTHuanjin	0x0F10	// �ƽ��ڻ���������,����������
#			define WP_Other_JinKaiXun	0x0F20	// ��Ѷ������
#			define WP_JKX               WP_Other_JinKaiXun
#			define WP_XJP               0x0F30	// �¼�������
#			define WP_LYSEE 			0x0F40  // ŦԼ������


#			define WP_INDEX_MZ1	 		0x0110 //"����һ";
#			define WP_INDEX_MZ2	 		0x0120 //"���޶�";
#			define WP_INDEX_OZ	 		0x0130 //"ŷ��";
#			define WP_INDEX_YZ1	 		0x0140 //"����һ";
#			define WP_INDEX_YZ2	 		0x0150 //"���޶�";
#			define WP_INDEX_YZ3	 		0x0160 //"������";



/*������*/
#define FOREIGN_MARKET			(0x8000) // ���
#	define WH_BASE_RATE			0x0100	// ��������
#	define WH_ACROSS_RATE		0x0200	// �������
#	define WH_FUTURES_RATE		0x0300  // �ڻ�