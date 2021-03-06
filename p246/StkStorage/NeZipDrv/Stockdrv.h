/*
网际风双向接口调用规范1.2  
文档使用UNICODE编码 微软雅黑字体，11字号
更新时间：                2014.06.20  
网际风官方网站  = "http://www.nezip.net" 
*/

#pragma	once

enum OEM_VERSION		//各种数据格式
{
	OEM_FXJ_50123		= 0X50123,		//分析家5.0版
	OEM_FXJ_2006		= 0X2006,		//分析家2006版
	OEM_TONGSHI_TUWEN	= 0X6666,		//通视图文接口
	OEM_MAIN_CLIENT		= 0X8888,		//网际风优先向该客户端申请数据，比如10档或逐笔或F10等
	OEM_SECONDE_CLIENT	= 0XFF8888,		//普通第三方调用方式，网际风不用主动向该用户申请数据
	RECEIVER_VERSION	= 20160325,		//接口数据版本
	SPLIT_MULTI_MARKET	= 20160325,		//分开不同市场，比如上海分开成上海和上海A股
};

typedef BOOL (CALLBACK *OEM_STOCKDRV_CALLBACK)(LPCVOID pTcpHead);		//回调函数原型，对于不需要建来接收窗口的用户，可以使用回调函数方式

enum KLINETYPE		//各个周期定义，用于第三方数据调用申请功能号
{
	TICK_KLINE			= 0,		//分时线	
	MIN5_KLINE			= 1,		//5分钟线	
	MIN15_KLINE			= 2,		//15分钟线
	MIN30_KLINE			= 3,		//30分钟线
	MIN60_KLINE			= 4,		//60分钟线
	DAY_KLINE			= 5,		//日线
	WEEK_KLINE			= 6,		//周线
	MONTH_KLINE			= 7,		//月线
	YEAR_KLINE			= 8,		//年
	MANY_DAY_KLINE		= 15,		//多日线
	MANY_MIN_KLINE		= 16,		//多分钟线
	MANY_SEC_KLINE		= 17,		//多秒线
	TRACE_KLINE			= 25,		//分笔成交
	SPLIT_KLINE			= 30,		//除权
	FINANCE_KLINE		= 31,		//财务
	SPLIT_FINANCE		= 32,		//除权财务
	MIN1_KLINE			= 35,		//1分钟线
	OEM_F10BASEINFO		= 40,		//F10基本资料
	NUM_MANY_DAY		= 50,		//多日线
	MAX_KLINETYPE		= 60,		//最大周期数
	OEM_REPORTDATA		= 500,		//单支股票实时数据
	OEM_ALLREPORT		= 501,		//所有实时数据
	OEM_INIT_CLIENT		= 510,		//申请初输化数据，如市场信息等
	OEM_HEART_ONLINE    = 511,		//心跳包说明客户端在线
	OEM_ASK_NO			= 555,		//服务器无该数据，请申请下一个数据
	OEM_ASK_TRUE		= 556,		//服务器已收到该次请求
	OEM_DATATYPE		= 8888,		//返回数据标识符
	OEM_SHOW			= 10001,	//显示接口
	OEM_HIDE			= 10002,	//隐藏接口
	OEM_CLOSE			= 10003,	//关闭接口
	OEM_FINANCE_FILE	= 10010,	//分析家财务数据文件
	OEM_F10_FILE	    = 10011,	//F10基本资料文件
	OEM_DATA_0526		= 0X0526,	//10档行情
	OEM_DATA_0551		= 0X0551,	//逐笔数据
	OEM_DATA_0552		= 0X0552,	//最近逐笔
	OEM_MARKETLABEL		= 0X8300,	//市场代码表
	OEM_LASTINFO		= 0X8301,	//初始化数据，如昨收，昨结算等
	COPYDATA_CLIENT		= 0XFFFFFFFF,//本地电脑使用CopyData方式
};

enum DATA_MAX
{
	MAX_KLINE_KINE			= 8,		//K线种类，标准K线，内外盘统计，大单统计，期货买卖性质
	STK_CODE_LEN			= 10,		//代码长度
	STK_LABEL_LEN			= STK_CODE_LEN + 2,	//市场+代码
	MAX_JISHU_NUM			= 10,		//最大技术数
	STK_NAME_LEN			= 32,		//名称长度
	MAX_BK_COUNT			= 50,		//最大可以所属几个板块
	MAX_SPLIT_COUNT			= 100,		//最大除权数
	IM_TITLE_LEN			= 64,		//信息地雷标题
	KLINEROOMCOUNT			= 100,		//最大K线存储节，一节512根K线
	MAX_KIND_COUNT			= 8000,		//系统能存储的最大股票数，包括板块和自定义等
	MAX_DAYKLINE_COUNT		= 500,		//日线历史最大量
	MAX_MIN5KLINE_COUNT		= 300,		//
	MAX_MIN1KLINE_COUNT		= 300,		//
	MAX_MINUTEKLINE_COUNT	= 300,		//分时
	MAX_MIN5WH_COUNT		= 1000,		//
	MAX_TRACEKLINE_COUNT	= 1000,		//
	MAX_EXKLINE_COUNT		= 300,		//扩展最大K线数量
	MAX_KLINE_SHOW			= 8000,		//显示最大K线数量
	MAX_FUTURES_COUNT		= 2000,		//系统能存储的最大期货品种个数
	MAX_STOCKS_COUNT		= 6000,		//系统能存储的最大品种个数
	MAX_DATABUF_SIZE		= 10240000,	//10M缓冲区最大值
};


enum MARKET			//市场定义
{
	MK_SH	= 0,		//上海证券
	MK_SZ	= 1,		//深圳证券
	MK_ZJ	= 10,		//中金期货
	MK_SQ	= 11,		//上海期货
	MK_DL	= 12,		//大连期货
	MK_BH	= 18,		//渤海商品
	MK_SJ	= 19,		//上海黄金
	MK_ZZ	= 20,		//郑州期货
	MK_HZ	= 21,		//恒指期货
	MK_MY	= 22,		//马来西亚
	MK_JP	= 23,		//日本期货
	MK_HK	= 30,		//香港市场
	MK_GJ	= 31,		//贵金属
	MK_GZ	= 32,		//广州贵金属
	MK_NY	= 33,		//纽约原油
	MK_TJ	= 34,		//天津贵金属
	MK_ID	= 40,		//国际指数
	MK_WH	= 41,		//外汇汇率
	MK_LM	= 42,		//伦敦LME
	MK_CB	= 43,		//CBOT期货
	MK_CM	= 44,		//纽约金属
	MK_ICE	= 45,		//美国ICE糖和棉花
	MK_IP	= 46,		//布伦特原油
	MK_CE	= 50,		//美国CME期货
	MK_NP	= 60,		//网际风内部
	MAX_MARKET_COUNT = 61	//所有市场数量
};

enum BLOCK		//系统板块定义
{
	BK_SHZS		= 0,	//上证指数
	BK_SHAG		= 1,	//上证A股	
	BK_SHBG		= 2,	//上证B股	
	BK_SHJJ		= 3,	//上证基金	
	BK_SHZQ		= 4,	//上证债券
	BK_SHZZ		= 5,	//上证转债
	BK_SHHG		= 6,	//上证回购
	BK_SHETF	= 7,	//上证ETF基金
	BK_SHKF		= 8,	//上证开放基金
	BK_SHQZ		= 9,	//上证权证
	BK_SHOT		= 10,	//上证其它

	BK_SZZS		= 15,	//深圳指数
	BK_SZAG		= 16,	//深证A股
	BK_SZBG		= 17,	//深证B股
	BK_SZJJ		= 18,	//深证基金	
	BK_SZZQ		= 19,	//深圳债券
	BK_SZZZ		= 20,	//深圳转债
	BK_SZHG		= 21,	//深圳回购
	BK_SZETF	= 22,	//深证ETF基金
	BK_SZKF		= 23,	//深证开放基金
	BK_SZQZ		= 24,	//深证权证
	BK_ZXQY	    = 25,	//中小企业
	BK_CYB	    = 26,	//创业板
	BK_SZOT		= 27,	//深证其它

	BK_ZJ		= 30,	//中金期货
	BK_SQ		= 32,	//上海期货
	BK_DL		= 33,	//大连期货			
	BK_ZZ		= 34,	//郑州期货

	BK_BOCE		= 40,	//渤海商品
	BK_GJ		= 41,	//贵金属
	BK_SGE		= 42,	//上海黄金
	BK_GZME		= 43,	//广东贵金属

	BK_ID		= 50,	//国际指数
	BK_HK		= 60,	//香港股票
	BK_HKFE		= 61,	//恒指期货
	BK_FOREX	= 64,	//外汇汇率
	BK_CBOT		= 65,	//CBOT期货
	BK_BURSA	= 66,	//马来西亚
	BK_TOCOM	= 67,	//日本期货
	BK_LME		= 68,	//伦敦LME			
	BK_COMEX	= 69,	//纽约金属
	BK_NYMEX	= 70,	//纽约期货
	BK_ICE		= 71,	//美棉、美糖
	BK_IP		= 72,	//布伦油
	BK_CME		= 73,	//美国CME期货
	BK_OEM		= 80,	//网际风
	BK_NEIBU	= 81,	//网际风内部

	BK_CHOOSE	= 85,	//自选股
	BK_ZHISHU	= 86,	//板块指数
	BK_FUTRUES	= 90,	//所有期货，以代码排序
	BK_STOCKS	= 91,	//所有股票，以代码排序
	BK_BYNAME	= 97,	//所有品种，以名称排序
	BK_BYLABEL	= 98,	//所有品种，以代码排序
	BK_BYSHIFT	= 99,	//所有品种，以大智慧索引排序
	BK_MAXCOUNT= 100,	//全部板块数量
};

enum TS_REPLY_ID		//通视规范数据返回功能号
{
	TS_DAYKLINE_ID	   = 0X0002,		//日线数据，通视中的FILE_HISTORY_EX
	TS_MIN5KLINE_ID	   = 0X0051,		//5分钟线，通视中的FILE_5MINUTE_EX
	TS_MIN1KLINE_ID	   = 0XA003,		//1分钟线，通视中没有定义
	TS_TICKKLINE_ID	   = 0X0004,		//分时，通视中的FILE_MINUTE_EX
	TS_TRACEKLINE_ID   = 0X0053,		//分笔，通视中没有定义
	TS_SPLIT_ID		   = 0X0006,		//除权数据，通视中的FILE_POWER_EX
	TS_F10BASE_ID	   = 0X1000,		//F10基本资料
	TS_NEWS_ID		   = 0X1002,		//新闻公告
	TS_HTMLEX_ID	   = 0X1004,		//HTML文件
	TS_SOFTWARE_ID	   = 0X2000,		//升级软件
	TS_FINANCE_ID	   = 0XA00B,		//财务数据
	TS_REPORT_ID	   = 0X3F001234,	//实时数据(通视标准)
	TS_FILEDATA_ID	   = 0X3F001235,	//历史数据标志(通视标准)
};

#pragma	pack(push, 1)	//表示以字节对齐，对于非字节对齐的，请一定要加上该语句

#ifndef EKE_HEAD_TAG
	#define	EKE_HEAD_TAG	0XFFFFFFFF		//数据头
#endif


struct RCV_HEAD		//16字节
{
	UINT		headTag;				//EKE_HEAD_TAG
	union
	{
		struct
		{
			char  marketEx[2];				//市场代码
			char  stockId[STK_CODE_LEN];	//股票代码,	以'\0'结尾
		};		  
		char	  stkLabel[STK_LABEL_LEN];	//市场代码 + 股票代码,以'\0'结尾
	};
	void SetLabel(LPCSTR stkLabel, BOOL isFinance = FALSE)
	{
		headTag = EKE_HEAD_TAG;
		if (isFinance)	//财务股票代码往后移两位
			::memmove(this->stockId,  stkLabel, STK_CODE_LEN);
		else
			::memmove(this->stkLabel, stkLabel, STK_LABEL_LEN);
	}
};

struct	RCV_REPORTV3	//通视3版实时数据结构
{
	WORD   size;			//	结构大小(158)
	UINT   time;			//成交时间，从1970年1月1日到现在的秒数，可以使用CTime进行转换
	union
	{
		struct
		{
			WORD  marketEx;
			char  stockId[STK_CODE_LEN];	//	市场代码	+ 股票代码,	以'\0'结尾
		};
		char      stkLabel[STK_LABEL_LEN];	//市场代码	+ 股票代码,	以'\0'结尾
	};
	char         name[STK_NAME_LEN];	//	股票名称,	以'\0'结尾
	float	lastClose;		//昨天收盘
	float	open;			//今日开盘	
	float	high;			//今日最高
	float	low;			//今日最低
	float	close;			//最新价格
	float	volume;			//总成交量
	float	amount;			//总成交金额（期货为持仓量）
	float	pricebuy[3];	//买入价一
	float	volbuy[3];		//买入量一
	float	pricesell[3];	//卖出价一
	float	volsell[3];		//卖出量一
	float	pbuy4;         //买入价四	
	float	vbuy4;         //买入量四						
	float	psel4;         //卖出价四
	float	vsel4;         //卖出量四	
	float	pbuy5;         //买入价五	
	float	vbuy5;         //买入量五						
	float	psel5;         //卖出价五
	float	vsel5;         //卖出量五
};

union RCV_TICK	//分时数据
{
	struct
	{
		UINT time;		// UCT
		float close;
		float volume;// (股票：手，期贷：合约，外汇：无)
		float amount;
	};
	RCV_HEAD head; 
};

union RCV_TRACE
{
	struct
	{
		UINT	time;		//	UCT
		float	close;
		float	volume;
		float	amount;
		union
		{
			struct
			{
				float	pricebuy[3];	//申买价1,2,3
				WORD	volbuy[3];		//申买量1,2,3
				float	pricesell[3];	//申卖价1,2,3
				WORD	volsell[3];		//申卖量1,2,3
			};
			struct
			{
				WORD   advance;			//上涨家数
				WORD   decline;			//下跌家数
			};
		};
	};
	RCV_HEAD	head;
};

union RCV_TRACEV50		//分时或分笔数V5.0(68字节)
{
	struct
	{
		UINT	time;	   //时间
		float	close;	   //收盘价(最新价)
		float	avPrice;   //均价
		float	volume;	   //成交量(手)
		float	amount;	   //成交额或期货持仓量
		union
		{
			struct
			{
				float   pricebuy[3];  //申买价1,2,3
				float   volbuy[3];	  //申买量1,2,3
				float   pricesell[3]; //申卖价1,2,3
				float   volsell[3];	  //申卖量1,2,3
			};
			struct
			{
				WORD  advance;//上涨家数
				WORD  decline;//下跌家数
			};
		};
	};
	struct
	{
		RCV_HEAD	head;
		float		lastClose;
		float		open;
	};
	void GetTongShiTick(RCV_TICK* pRcvTick)		//转为通视分时结构
	{
		pRcvTick->time   = time;
		pRcvTick->close  = close;
		pRcvTick->volume = volume;
		pRcvTick->amount = amount;
	}
	void GetFoxTrace(RCV_TRACE* pRcvTrace)		//转为飞狐结构
	{
		pRcvTrace->time	   = time;
		pRcvTrace->close   = close;
		pRcvTrace->volume  = volume;
		pRcvTrace->amount  = amount;
		int i;
		for (i = 0; i < 3; i++)
		{
			pRcvTrace->pricebuy[i] = pricebuy[i];
			pRcvTrace->volbuy[i]   = (WORD)volbuy[i];	//明显Bug，挂单量不能超过0XFFFF
		}
		for (i = 0; i < 3; i++)
		{
			pRcvTrace->pricesell[i]	= pricesell[i];
			pRcvTrace->volsell[i]   = (WORD)volsell[i];
		}
	}
};

//补日线、5分钟、1分钟线结构一致
union	RCV_KLINE		//标准K线
{
	struct
	{
		UINT	time;	  //时间
		float	open;	  //开盘价
		float	high;	  //最高价
		float	low;	  //最低价
		float	close;	  //收盘价
		float	volume;	  //成交量
		float	amount;   //成交金额
		union
		{
			struct
			{
				WORD   advance;//上涨家数
				WORD   decline;//下跌家数
			};
			float	  outerVol;//外盘(主动买量)
		};
	};
	struct
	{
		RCV_HEAD  head;
		char	  sameDay;			//sameDay -1 读全部；0不读出当天数据
		bool	  isSplit;			//是否进行复权处理
		char	  splitLeft;		//是否向左复权（历史方向），通常的做法
		char	  many;				//多秒，多分钟，多日线标识：0正常周期；10多秒；20多分钟；30多日
	};
};

union RCV_SPLIT   //补充除权数据
{
	struct
	{
		UINT   time;
		float  give;			//每股送
		float  allocate;		//每股配
		float  allocatePrice;	//每股配价
		float  earnings;		//每股红利
	};
	RCV_HEAD	head;
};

union RCV_FINANCE	//财务数据结构（152）
{
	struct
	{
		UINT	time;		//0  更新日期
		float	zgb;		//1  总股本(万股)
		float	gjg;		//2  国家股
		float	fqrfrg;		//3	 发起法人股
		float	frg;		//4	 法人股
		float	Bg;			//5	 B股
		float	Hg;			//6	 Ｈ股
		float	ltAg;		//7	 流通A股
		float	zgg;		//8	 职工股
		float	a2zpg;		//9	 A2转配股
		float	zzc;		//10 总资产(千元)
		float	ldzc;		//11 流动资产
		float	gdzc;		//12 固定资产
		float	wxzc;		//13 无形资产
		float	cqtz;		//14 长期投资
		float	ldfz;		//15 流动负债
		float	cqfz;		//16 长期负债
		float	zbgjj;		//17 资本公积金
		float	mggjj;		//18 每股公积金
		float	gdqy;		//19 股东权益
		float	zysr;		//20 主营收入
		float	zylr;		//21 主营利润
		float	qtlr;		//22 其他利润
		float	yylr;		//23 营业利润
		float	tzlr;		//24 投资收益
		float	btsr;		//25 补贴收入
		float	yywsz;		//26 营业外收支
		float	sytz;		//27 损益调整
		float	lrze;		//28 利润总额
		float	shlr;		//29 税后利润
		float	jlr;		//30 净利润
		float	wfplr;		//31 未分配利润
		float	mgwfp;		//32 每股未分配
		float	mgsy;		//33 每股收益
		float	mgjz;		//34 每股净资
		float	tzmgjj;		//35 调整每股净资
		float	gdqybl;		//36 股东权益比率
		float	jzsyl;		//37 净资收益率
	};
	RCV_HEAD	head;
};

//飞狐财务数据结构（228字节）
 union RCV_FINANCEV50
{
	 struct
	 {
		 struct	//RCV_FINANCE	//分析家格式（152）
		 {
			 UINT	time;		//0	  更新日期
			 float	zgb;		//1	  总股本(万股)
			 float	gjg;		//2	  国家股
			 float	fqrfrg;		//3	  发起法人股
			 float	frg;		//4	  法人股
			 float	Bg;			//5	  B股
			 float	Hg;			//6	  Ｈ股
			 float	ltAg;		//7	  流通A股
			 float	zgg;		//8	  职工股
			 float	a2zpg;		//9	  A2转配股
			 float	zzc;		//10  总资产(千元)
			 float	ldzc;		//11  流动资产
			 float	gdzc;		//12  固定资产
			 float	wxzc;		//13  无形资产
			 float	cqtz;		//14  长期投资
			 float	ldfz;		//15  流动负债
			 float	cqfz;		//16  长期负债
			 float	zbgjj;		//17  资本公积金
			 float	mggjj;		//18  每股公积金
			 float	gdqy;		//19  股东权益
			 float	zysr;		//20  主营收入
			 float	zylr;		//21  主营利润
			 float	qtlr;		//22  其他利润
			 float	yylr;		//23  营业利润
			 float	tzlr;		//24  投资收益
			 float	btsr;		//25  补贴收入
			 float	yywsz;		//26  营业外收支
			 float	sytz;		//27  损益调整
			 float	lrze;		//28  利润总额
			 float	shlr;		//29  税后利润
			 float	jlr;		//30  净利润
			 float	wfplr;		//31  未分配利润
			 float	mgwfp;		//32  每股未分配
			 float	mgsy;		//33  每股收益
			 float	mgjz;		//34  每股净资
			 float	tzmgjj;		//35  调整每股净资
			 float	gdqybl;		//36  股东权益比率
			 float	jzsyl;		//37  净资收益率
		 };
		 float	jyxjlr;		    //38  经营现金流入
		 float	jyxjlc;		    //39  经营现金流出
		 float	jyxjll;		    //40  经营现金流量
		 float	tzxjlr;		    //41  投资现金流入
		 float	tzxjlc;		    //42  投资现金流出
		 float	tzxjll;		    //43  投资现金流量
		 float	czxjlr;		    //44  筹资现金流入
		 float	czxjlc;		    //45  筹资现金流出
		 float	czxjll;		    //46  筹资现金流量
		 float	xjjdjw;		    //47  现金及等价物
		 float	yszkzzl;	    //48  应收账款周转率
		 float	chzzl;		    //49  存货周转率
		 float	gdzs;		    //50  股东总数
		 float	fxj;		    //51  发行价
		 float	fxl;		    //52  发行量
		 float	zyywzzl;	    //53  主营业务增长率
		 float	shlrzzl;	    //54  税后利润增长率
		 float	jzczzl;		    //55  净资产增长率
		 float	zzczzl;		    //56  总资产增长率
	 };
	RCV_HEAD	head;
};

//dataType ==  TS_F10BASE_ID
//dataFlag：市场标识，比如'HS'、'ZS'
//fileName：文件名
//fileTime ：文件日期

//dataType ==  TS_NEWS_ID
//dataFlag = 消息来源：2 上交所公告；4 深交所公告；6 财经报道；-1未知提供者
 //fileName 包含目录的文件名, 目录名为消息来源
//如:  "上交所消息\\0501Z012.TXT", "新兰德\\XLD0001.TXT"
//serialNo = 序列号

//dataType ==  TS_HTMLEX_ID
//dataFlag 保留
 //fileName为URL

//dataType == TS_SOFTWARE_ID，升级软件
//dataFlag 分析软件类型
//fileName 分析软件 ID 特征字符串 + '\\' + 文件名
//如 "TongShi\\TS\\RECEIVE\\RECEIVE.EXE", 
//特征字符串： "TongShi"； 文件名："TS\\RECEIVE\\RECEIVE.EXE" 
//特征字符串 和 文件名及其含义由分析软件商定义

struct RCV_FILE_HEADEx
{
	UINT    dataFlag;// 文件子类型
	UINT    dataLen;// 文件长度
	union
	{
		UINT  serialNo;// 序列号, 对股评
		UINT  fileTime;// 文件创建时间
	};
	char      fileName[MAX_PATH];// 文件名 or URL
};

//查询方式通知消息
//wParam = STOCKDATA有股票数据
//wParam = FILEDATA有文件数据文件
//  lParam 指向 RCV_DATA结构;
//返回 1 已经处理, 0 未处理或不能处理, 目前该返回值被忽略
// 注一:
//  记录数表示行情数据和补充数据(包括 Header)的数据包数, 对文件类型数据 = 1
// 注二:
//  若 disk = FALSE, pData 为数据缓冲区指针
// disk = TRUE, 数据使用磁盘形式提供，pData指向存放该文件的位置，然后到指定位置读出相应数据
struct RCV_DATA	//288字节，通视接口头部
{
	int		dataType;			//数据类型
	int		count;				//记录数,	表示行情数据和补充数据(包括	Header)的数据包数,	对文件类型数据,	=	1
	RCV_FILE_HEADEx	file;		//文件接口,	存放信息地雷等相关内容
	BOOL		disk;			// 文件是否已存盘的文件;
	union
	{
		RCV_HEAD*			pHead;			//该品种代码
		RCV_REPORTV3*		pReport3;		//行情数据
		RCV_KLINE*			pKline;			//历史K线数据
		RCV_TICK*			pTick;			//分时
		RCV_TRACE*			pTrace;			//分笔
		RCV_TRACEV50*		pTrace50;		//分笔
		RCV_SPLIT*			pSplit;			//财务数据
		RCV_FINANCE*		pFinance;		//财务数据
		RCV_FINANCEV50*		pFinance50;		//财务数据
		PSTR				pData;			//数据缓冲区
		LPCVOID				pDataBuf;		//数据缓冲区或文件路径
	};
	void Init()
	{
		::memset(this, 0, sizeof RCV_DATA);
		pDataBuf = this + 1;
	}
	int GetHeadSize()
	{
		return sizeof RCV_DATA;
	}
	int GetSplitDataLen()
	{
		return GetHeadSize() + count * sizeof RCV_SPLIT;
	}
	int GetFinaceDataLen()
	{
		return GetHeadSize() + count * sizeof RCV_FINANCE;
	}
	int GetKlineDataLen()
	{
		return GetHeadSize() + count * sizeof RCV_KLINE;
	}
	int GetReportV3Len()
	{
		return GetHeadSize() + count * sizeof RCV_REPORTV3;
	}
};
	
//GetStockDrvInfo(int dataType, LPCVOID pDataBuf)	取得股票驱动信息，dataType 功能号，pDataBuf 缓冲区，至少32字节
#define	RI_IDSTRING			1		//返回厂商名长度(包括\0), pDataBuf 为厂商名（"网际风软件有限公司"）
#define	RI_IDCODE			2		//返回信息卡 ID 号（0x78001234）, pDataBuf 为字符串形式（ "78001234"）
#define	RI_VERSION			3		//返回信息卡版本号（300）, pDataBuf 为字符串版本（"3.00")
#define	RI_V2SUPPORT		6		//返回是否支持深圳SJS库结构, pDataBuf无效
#define	STKCODE_LEN		    10		//股号数据长度,国内市场股号编码兼容钱龙
#define	STKNAME_LEN			32		//股名长度
#define	RI_NETPCID			1000	//返回电脑硬件编号长度(包括\0)，pDataBuf电脑硬件编号（用于验证合法用户）


/////////通视3.0接口扩展，提供功能强大的第三方数据调用

struct TCP_ASK_HEAD	//申请数据辅助参数设置(61字节)
{
	union
	{
		struct
		{
			char   marketEx[2];				//'HS'上海；'ZS'深圳；'JZ'中金所；'QS'上期
			char   stockId[STK_CODE_LEN];	//市场代码 + 股票代码,以'\0'结尾
		};
		char       stkLabel[STK_LABEL_LEN];	//市场代码 + 股票代码,以'\0'结尾，形如SH000300
	};
	float          point;			//放大倍数，用于将价格整数转换成浮点数，比如有两位小数，则为100.0f
	bool           askServer;		//0：读出客户端数据，立即返回数据（推荐方式）；1：向远程服器申请数据，等待与服务器同步后才返回
									//仅支持 日线、5分钟线、1分钟线、分时、分笔，除了明显认为数据不全时才使用。
									//同步服务器数据返回的数据使用默认值(sameDay = false，isSplit = false)，且所有连接网际风的用户将同步更新该数据
	KLINETYPE		klineType;		//数据周期，形如DAY_KLINE，日线等，当many有置相应数据时多少秒，多少分钟，多少天
	union
	{
		UINT		begin;			//从哪一根开始申请，由后往前，即由现在时间往历史方向申请(未支持)
		UINT		allCount;		//应答时用来填写服务器当前总数量(未支持)
	};
	UINT		count;				//申请数量，0表示全部，应答时返回实际有效数据量
	UINT		data[4];			//其它数据，比如除权方向等
	union
	{
		char		dataEx[16];		//16字节拓展数据
		struct
		{
			bool	sameDay;		//true读全部；false不读出当天数据
			bool	isSplit;		//是否进行复权处理
			char	splitLeft;		//1向左复权（历史方向），通常的做法；0向右方向
			char	many;			//多秒，多分钟，多日线标识：0正常周期；10多秒；20多分钟；30多日
			WORD	periods;		//多少个周期
		};
	};
	void Init(LPCSTR stkLabel, KLINETYPE klineType, UINT begin, UINT count, bool sameDay = false, bool isSplit = false, char splitLeft = 1, bool askServer = false)
	{
		::memset(this, 0, sizeof TCP_ASK_HEAD);
		if (!stkLabel)
			stkLabel = "SH000001";
		::memmove(this->stkLabel, stkLabel, STK_LABEL_LEN);
		this->klineType = klineType;
		this->begin = begin;
		this->count = count;
		this->sameDay = sameDay;
		this->isSplit = isSplit;
		this->splitLeft = splitLeft;
		this->askServer = askServer;
	}
	void Init()
	{
		::memset(this, 0, sizeof TCP_ASK_HEAD);
	}
};

union NEZIP_PTR
{
	UINT		value;			//数值
	UINT64		value64;		//64位值
	LPSTR		pData;			//字符串指针
	LPWSTR		pDataW;			//宽字符串指针
	LPCVOID	    pDataBuf;		//数据区指针
};

struct  NEZIP_KLINEINFO //K线性质(37)字节
{
	char		isStkLabel;		//0 使用REPORTDATA申请方式； 1 使用股票代码申请方式
	union
	{
		LPCVOID  pReport;
		char     stkLabel[STK_LABEL_LEN];
	};
	KLINETYPE klineType;			//周期
	union
	{
		UINT begin;			//从哪一根开始申请，由后往前，即由现在时间往历史方向申请(预留功能)
		UINT allCount;		//应答时用来填写服务器当前总数量(预留功能)
		int	 refresh;		//-1全部重写，0追加，1覆盖时间段一致数据，向网际风提供Ｋ线写入方式
	};
	UINT	klineCount;		//申请数量，0表示全部，应答时返回实际有效数据量
	bool	sameDay;		//true读全部；false不读出当天数据
	char	dataFlag;		//0普通Ｋ线，其它预留拓展数据(预留功能)
	bool	askServer;		//0：立即返回数据（推荐方式）；1：先到远程服务器同步数据后再返回
	union
	{
		struct
		{
			bool  jingJia;		//读当前数据是否包括集合竞价
			char  volumeFlag;	//当天数据成交量处理方式，0：Fox(成交量不做处理)；1：Nezip(转为分量，补充缺少K线)；100：OEM(补充缺少Ｋ线，没有转为分量)
		};		  
		struct	  
		{		  
			bool  isSplit;		//是否进行复权处理
			char  splitLeft;	//是否向左复权（历史方向），通常的做法
		};
	};
	char	many;				//多秒，多分钟，多日线标识：0正常周期；10多秒；20多分钟；30多日(预留功能)；100当天Ｋ线；101当天分时；102当天分笔
	WORD	periods;			//多少个周期(预留功能)
	float	point;				//放大倍数，用于将价格整数转换成浮点数，比如有两位小数，则为100.0f
	void AskKlineByLabel(LPCSTR stkLabel, KLINETYPE klineType, UINT begin, UINT count, bool sameDay = false, char dataFlag = 0, bool askServer = false,
						 bool isSplit = false, char splitLeft = 1, char many = 0, WORD periods = 0)
	{
		::memset(this, 0, sizeof NEZIP_KLINEINFO);
		isStkLabel = 1;
		::memmove(this->stkLabel, stkLabel, STK_LABEL_LEN);
		this->klineType  = klineType;
		this->begin      = begin;
		this->klineCount = count;
		this->sameDay    = sameDay;
		this->dataFlag   = dataFlag;
		this->askServer  = askServer;
		this->isSplit    = isSplit;
		this->volumeFlag = splitLeft;
		this->many       = many;
		this->periods    = periods;
	}
	void AskKlineByReport(LPCVOID pReport, KLINETYPE klineType, UINT begin, UINT count, bool sameDay = false, char dataFlag = 0, bool askServer = 0,
						 bool isSplit = false, char splitLeft = true, char many = 0, WORD periods = 0)
	{
		::memset(this, 0, sizeof NEZIP_KLINEINFO);
		this->klineType = klineType;
		this->pReport   = pReport;
		this->begin     = begin;
		this->klineCount = count;
		this->sameDay   = sameDay;
		this->dataFlag  = dataFlag;
		this->askServer = askServer;
		this->isSplit   = isSplit;
		this->volumeFlag = splitLeft;
		this->many     = many;
		this->periods  = periods;
	}
};

struct TCP_DATA_HEAD		//第三方数据调用TCP数据包头(109字节)
{
	KLINETYPE     dataType;			//数据头标识： NEZIP_DATATYPE 8888
	OEM_VERSION   dataVersion;		//版本号
	KLINETYPE     klineType;		//功能号：0X0501登录成功； 0X0526 十档；0X0551逐笔，
	union  //56字节
	{
		struct  //网际风内部数据
		{
			unsigned __int64 socket;	//8字节
			char    tdxClientHead[10];	//10字节
			char    replayMode;
		};
		NEZIP_KLINEINFO klineInfo;			//K线性质(33)字节
		char			clientPackInfo[56];	//内部识别数据，原样直接返回
		NEZIP_PTR		pointersEx[7];		//传输某些指针值
		WCHAR			strBuf[28];			//指标名称
	};
	NEZIP_PTR    pointers;				//某些指针
	UINT         data[3];				//某些指定的值
	char         zipFlag;				//压缩标识：0没有压缩，1有压缩
	UINT         unZipDataLen;			//压缩前数据长度
	UINT         zipDataLen;			//压缩后数据长度
	UINT         count;					//多少组数据
	union
	{
		UINT	 value;					//数值
		UINT64   value64;				//64位值
		LPSTR	 pData;					//字符串指针
		LPWSTR   pDataW;				//宽字符串指针
		LPCVOID  pDataBuf;				//数据区指针
	};

	//接着是存放申请或返回数据缓冲区
	TCP_DATA_HEAD()
	{
		Init();
	}
	void Init(OEM_VERSION dataVersion, KLINETYPE klineType, LPCVOID pClientPackInfo, char zipFlag, UINT unZipDataLen, UINT zipDataLen, UINT count)
	{
		this->dataType		= OEM_DATATYPE;
		this->dataVersion	= dataVersion;
		this->klineType		= klineType;
		this->zipFlag		= zipFlag;
		this->unZipDataLen	= unZipDataLen;
		this->zipDataLen	= zipDataLen;
		this->count = count;
		if (pClientPackInfo)
			::memmove(this->clientPackInfo, pClientPackInfo, sizeof this->clientPackInfo);
	}
	UINT GetPackLen()
	{
		return zipDataLen + sizeof TCP_DATA_HEAD;	//数据+头部
	}
	void Init()		//清除数据
	{
		::memset(this, 0, sizeof TCP_DATA_HEAD);
		this->pDataBuf	  = this + 1;
		this->dataType	  = KLINETYPE::OEM_DATATYPE;
		this->dataVersion = OEM_MAIN_CLIENT;
		this->klineType	  = KLINETYPE::OEM_DATATYPE;
		this->pointers.pDataBuf = this;
		::wcscpy_s(this->strBuf, L"第三方数据调用");
	}
	void InitTdx(unsigned __int64 socket, LPCVOID pDataBuf)		//通达信相关信息
	{
		this->socket = socket;
		::memmove(this->tdxClientHead, pDataBuf, 10);
	}
};

struct TCP_ASK_DATA
{
	TCP_DATA_HEAD	dataHead;
	TCP_ASK_HEAD	askHead;
	TCP_ASK_DATA()
	{
		Init();
	}
	void Init()
	{
		this->dataHead.Init();
		this->askHead.Init();
	}
};

struct OEM_STOCKID					//证券标识，以索引号方式标识每个品种
{
	union
	{
		UINT		index;			//该品种编号（前两个字节为市场，后两个字节为偏移）
		struct
		{
			union
			{
				char	market[2];
				WORD	marketId;	//市场代码
			};
			short		shift;		//在该市场NPMARKET::m_Siff中的偏移
		};
	};
};

struct OEM_HEAD			//数据包头(7字节)
{								
	WORD dataType;		//请求/应答类型，RCV_DZH_MARKET等
	char status;		//当为应答包时：1成功；0失败；2离线
	UINT packIndex;		//请求包索引号
};

struct OEM_MARKETINFO			//市场内容(82字节)
{
	union
	{
		WORD	marketId;		//市场代码, 'HS', 'SZ', 'JZ', 'HW' ..... 
		char	market[2];		//英文简写, "SH", "SZ", "ZJ", "WH" .....
	};
	char		name[STK_NAME_LEN];	//市场名称(上海交易所)
	int			localTime;			//时区
	WORD		marketKind;			//市场属性(1 股票；3 期货)
	WORD		reportKind;			//实时数据属性(1 Level2；4普通点播)
	short		periodCount;		//交易时段个数
	short		openTime[8];		//开市时间 1,2,3,4,5 (开盘分钟数，比如 0X023A（570）表示 9:30) 
	short		closeTime[8];		//收市时间 1,2,3,4,5
	UINT		date;				//数据日期（201301010）
	WORD		count;				//该市场的证券个数
};

struct OEM_STOCKINFO		// 证券(64字节)
{
	WORD	shift;					//序号
	char	stockId[STK_CODE_LEN];	//股票代码,以'\0'结尾
	char	name[STK_NAME_LEN];		//股票名称,以'\0'结尾
	char	block;					//品种属性，0指数，1 A、B股，2 基金, 3 债券，4 质押 ，7 期货，8 期货指数
	char	pointCount;				//小数点个数0X00、0X01、0X02、0X03	
	short	hand;					//每手股数
	UINT	temp1;
	UINT	limitDown;				//涨停
	UINT	temp2;
	UINT	limitUp;				//跌停
};

struct OEM_MARKET_REPLY		// 市场信息需要变动，自动发送
{
	OEM_HEAD			head;
	OEM_MARKETINFO		marketInfo;
	OEM_STOCKINFO		stockInfo[2];	//每个品种的相关信息
	int GetHeadSize()
	{
		return sizeof OEM_HEAD + sizeof OEM_MARKETINFO;
	}
	int GetDataLen()
	{
		return GetHeadSize() + marketInfo.count * sizeof OEM_STOCKINFO;
	}
};

struct	OEM_REPORTV5	//实时数据V5.0，带*表示网际风内部数据，请跳过
{
	WORD	size;		//OEM_REPORTV5结构体大小(532字节，可能会改变)
	INT		index;		//网际风内部索引*
	MARKET	market;		//市场0:MK_SH;1:MK_SZ，表明是上海、深圳等市场*
	union
	{
		struct
		{
			WORD	marketEx;				//市场代码(使用该标识区分不同的市场)
			char	stockId[STK_CODE_LEN];	//证券代码
		};
		char		stkLabel[STK_LABEL_LEN];
	};
	char			name[STK_NAME_LEN];			//股票名称
	char			pinYin[STK_LABEL_LEN];		//汉字拼音简称
	union
	{
		OEM_STOCKID	stockIndex;
		UINT	dzhIndex;		//该品种编号（前两个字节为市场，后两个字节为偏移）
	};
	char	block;			//所属系统板块，BK_SHAG，BK_SZAG，表明是上海Ａ股，深圳Ａ股系统板块*
	bool	isIndex;		//是否指数*
	bool	isDaPan;		//是否大盘*
	char	temp12;			//
	float	point;			//计算用的小数点*
	WORD	hand;			//一手多少股*
	short	temp18;			//预留*
	WORD	financeDate;	//财务更新时间*
	WORD	splitDate;		//除权更新时间*
	float	lastClose;		//昨天收盘
	float	limitUp;		//涨停价
	float	limitDown;		//跌停价
	float	volume5;		//5天均量
	int		lastPosition;	//昨持仓量
	float	lastAverage;	//期货前结算价
	float	priceClosed;	//收盘作业价
	int		pinLv;			//使用频率，该值大说明该品种经常被用户查看，优先处理*
	UINT	marketTime;		//该值相同表示处于同一个交易市场同一个交易时间段*
	float	temp19;			//空余

	//以下区域初始化时清零
	UINT		time;			//成交时间
	char		closed;			//是否已经收盘作业，0未收盘，-1数据缺少，不允许自动收盘，1已收盘*
	int			lastFoot;		//最后处理分钟数*
	UINT		openDate;		//市场开盘日期零点
	UINT		openTime;		//市场开盘时间
	UINT		closeDate;		//市场日线日期零点
	float		temp84;			//*
	float		temp85;			//*
	short		temp86;			//*

	float		open;			//今日开盘
	float		high;			//今日最高
	float		low;			//今日最低
	float		close;			//最新价格
	float		volume;			//总成交量
	float		amount;			//总成交金额
	float		outerVol;		//外盘	
	float		pricesell[10];	//申卖价1,2,3,4,5
	float		volsell[10];	//申卖量1,2,3,4,5
	float		vsellCha[10];	//申卖量变化
	float		pricebuy[10];	//申买价1,2,3,4,5
	float		volbuy[10];		//申买量1,2,3,4,5
	float		vbuyCha[10];	//申买量变化*
	float		avBuy;			//买均*
	float		avSell;			//卖均*
	float		buyAll;			//总买*
	float		sellAll;		//总卖*
	UINT		allTrace;		//逐笔总数*
	UINT		traceCount;		//总分笔数*
	short		milliseconds;	//毫秒数*
	int			position;		//期货持仓
	float		avPrice;		//期货的结算价（平均价）
	char		isBuy;			//-1: 与上在笔相比下跌；1:上涨； 2:平盘且上一笔上涨；-2:平盘且上一笔下跌
	float		nowv;			//分笔成交量
	float		nowa;			//成交额(期货仓差)

	float		changeHand;		//换手率*
	float		weiBi;			//委比*
	float		liangBi;		//量比*
	float		lastVolume;		//上一分钟成交量*
	float		lastAmount;		//上一分钟成交额*
	float		lastBuyVol;		//上一分钟成外盘*
	int			temp[10];		//预留*

	OEM_REPORTV5()
	{
		Clear();
	}
	void Clear()
	{
		::memset(this, 0, sizeof OEM_REPORTV5);
		this->size = (WORD)(sizeof OEM_REPORTV5);
		this->point = 100.0f;
	}
	
	int GetTongShiReport(RCV_REPORTV3* pReportV3)	//转为通视格式
	{
		pReportV3->size = sizeof RCV_REPORTV3;
		pReportV3->time= time;
		::strcpy_s(pReportV3->stkLabel, stkLabel);
		::strcpy_s(pReportV3->name, name);
		pReportV3->lastClose= lastClose;
		pReportV3->open		= open;
		pReportV3->high		= high;
		pReportV3->low		= low;
		pReportV3->close	= close;
		pReportV3->volume	= volume;
		pReportV3->amount	= amount;
		for (int i = 0; i < 3; i++)
		{
			pReportV3->pricebuy[i]	= pricebuy[i];
			pReportV3->volbuy[i]	= volbuy[i];
			pReportV3->pricesell[i]	= pricesell[i];
			pReportV3->volsell[i]	= volsell[i];
		}
		pReportV3->pbuy4  = pricebuy[3];
		pReportV3->vbuy4  = volbuy[3];
		pReportV3->psel4  = pricesell[3];
		pReportV3->vsel4  = volsell[3];
		pReportV3->pbuy5  = pricebuy[4];
		pReportV3->vbuy5  = volbuy[4];
		pReportV3->psel5  = pricesell[4];
		pReportV3->vsel5  = volsell[4];

		return pReportV3->size;
	}
};

struct BASEINFO		    //财务除权数据(2276字节)
{
	UINT	time;		//发布日期		0
	UINT	baoGao;		//报告日期
	UINT	shangShi;	//上市日期
	float	mgsy;		//每股收益(元)
	float	mgjzc;		//每股净资产(元)
	float	jzcsyl;		//净资产收益率(%)
	float	mgjyxj;		//每股经营现金
	float	mggjj;		//每股公积金(元)
	float	mgwfp;		//每股未分配利润(元)
	float	gdqybl;		//股东权益比率(%)
	float	jlrtb;		//净利润同比		10
	float	zysytb;		//主营收益同比
	float	xsmll;		//销售毛利率
	float	mgjz;		//每股净值(元)	
	float	zzc;		//总资产(万元)
	float	ldzc;		//流动资产(万元)
	float	gdzc;		//固定资产(万元)
	float	wxzc;		//无形资产(万元)
	float	ldfz;		//流动负债(万元)	
	float	cqfz;		//长期负债(万元)
	float	zfz;		//总负债				20
	float	gdqy;		//股东权益(万元)
	float	zbgjj;		//资本公积金(万元)
	float	jyxjl;		//经营现金流量
	float	tzxjl;		//投资现金流量
	float	czxjl;		//筹资现金流量
	float	xjzje;		//现金增加额
	float	zysr;		//主营业务收入(万元)
	float	zylr;		//主营业务利润(万元)
	float	yylr;		//营业利润	
	float	tzsy;		//投资收益			30
	float	qtlr;		//其它业务利润(万元)
	float	lrze;		//利润总额(万元)
	float	jlr;		//净利润(万元)
	float	wfplr;		//未分配利润(万元)
	float	zgb;		//总股本(万股)
	float	wxsAg;		//无限售股合计
	float	ltAg;		//流通A股(万股)	
	float	Bg;			//B股(万股)
	float	Hg;			//Ｈ股(万股)，境外上市股
	float	qtltg;		//其它流通股			40
	float	xsghj;		//限售股合计
	float	gjg;		//国家股(万股)
	float	frcg;		//国有法人股
	float	frg;		//境内法人股(万股)
	float	jnzrrg;		//境内自然人股
	float	fqrfrg;		//其他发起人股(万股)
	float	mjfrg;		//募集法人股
	float	jwfrg;		//境外法人股
	float	jwzrrg;		//境外自然人股
	float	yxg;		//优先股或其他	50(大智慧204字节结构)
	float	temp[5];	//备用
	char	tmep1[10];
	int		temp2;
	bool	isSort;			//已排序
	char	temp22;			//

	UINT		splitCount;//除权次数
	RCV_SPLIT	split[MAX_SPLIT_COUNT];
	char		stkLabel[STK_LABEL_LEN];	//代码表
	char		temp12[STK_LABEL_LEN];		//
	UINT64	verHash;	//版本号
	WORD GetDateDifference2000(BOOL isSplit)	//离2001年多少天, isSplit 1除权，0财务
	{
		UINT time = 946656000;		//2000年时间
		if (isSplit && splitCount)
			time = split[splitCount - 1].time;
		else
			time = this->time;
		if (time < 946656000)
			return 0;
		return (WORD)((time - 946656000) / 86400);
	}
	UINT GetSplit(RCV_SPLIT* &pSplit, BOOL addHead = FALSE)		//是否带头部
	{
		UINT count = 0;
		if (addHead)
		{
			pSplit->head.SetLabel(this->stkLabel);
			pSplit++;
			count++;
		}
		::memmove(pSplit, split, splitCount * sizeof RCV_SPLIT);
		pSplit += splitCount;
		count += splitCount;

		return count;
	}
	void GetFinance(RCV_FINANCEV50* pFinance)
	{
		pFinance->time		= time;
		pFinance->zgb		= zgb;			//1	总股本(万股)
		pFinance->gjg		= gjg;			//2	国家股
		pFinance->fqrfrg	= fqrfrg;		//3	发起法人股
		pFinance->frg		= frg;			//4	法人股
		pFinance->Bg		= Bg;			//5	B股
		pFinance->Hg		= Hg;			//6	Ｈ股
		pFinance->ltAg		= ltAg;			//7	流通A股
		pFinance->zgg		= 0;			//8	职工股
		pFinance->a2zpg		= 0;			//9	A2转配股
		pFinance->zzc		= zzc;			//10 总资产(千元)
		pFinance->ldzc		= ldzc;			//11 流动资产
		pFinance->gdzc		= gdzc;			//12 固定资产
		pFinance->wxzc		= wxzc;			//13 无形资产
		pFinance->cqtz		= 0;			//14 长期投资
		pFinance->ldfz		= ldfz;			//15 流动负债
		pFinance->cqfz		= cqfz;			//16 长期负债
		pFinance->zbgjj		= zbgjj;		//17 资本公积金
		pFinance->mggjj		= mggjj;		//18 每股公积金
		pFinance->gdqy		= gdqy;			//19 股东权益
		pFinance->zysr		= zysr;			//20 主营收入
		pFinance->zylr		= zylr;			//21 主营利润
		pFinance->qtlr		= qtlr;			//22 其他利润
		pFinance->yylr		= 0;			//23 营业利润
		pFinance->tzlr		= 0;			//24 投资收益
		pFinance->btsr		= 0;			//25 补贴收入
		pFinance->yywsz		= 0;			//26 营业外收支
		pFinance->sytz		= 0;			//27 损益调整
		pFinance->lrze		= lrze;			//28 利润总额
		pFinance->shlr		= 0;			//29 税后利润
		pFinance->jlr		= jlr;			//30 净利润
		pFinance->wfplr		= wfplr;		//31 未分配利润
		pFinance->mgwfp		= mgwfp;		//32 每股未分配
		pFinance->mgsy		= mgsy;			//33 每股收益
		pFinance->mgjz		= mgjz;			//34 每股净资
		pFinance->tzmgjj	= 0;			//35 调整每股净资
		pFinance->gdqybl	= gdqy;			//36 股东权益比率
		pFinance->jzsyl		=  jzcsyl;		//37 调整每股净资
	}
};

class CReport10_32		//向网际风提供10档数据
{
	typedef struct
	{
		unsigned long		price;	//委托价格[*放大倍数]
		__int64				volume;	//委托量[股]
	} tagBuySellOneLevel;
public:
	TCP_ASK_HEAD	askHead;	//返回申请数据相关信息
public:
	unsigned char		ipushtype;	//推送类型,‘2’，网际风忽略
	unsigned char		codetype;	//商品类型，网际风忽略
	unsigned char		code[6];	//商品代码，网际风忽略
	unsigned int		close;		//昨收价格[*放大倍数]
	unsigned int		open;		//开盘价格[*放大倍数]
	unsigned int		high;		//最高价格[*放大倍数]
	unsigned int		low;		//最低价格[*放大倍数]
	unsigned int		now;		//最新价格[*放大倍数]
	double				amount;		//总成交金额[元]
	__int64				volume;		//总成交量[股]
	unsigned int		records;	//总成交笔数[笔]，即总逐笔数，用来标识每一个逐笔，在申请逐笔数据时会用到
	tagBuySellOneLevel	buy[10];	//10档委买盘
	tagBuySellOneLevel	sell[10];	//10档委卖盘
	unsigned int		vbuyprice;	//委买加权平均价格[*放大倍数]
	__int64				vbuyvolume;	//委买总量[股]
	unsigned int		vsellprice;	//委卖加权平均价格[*放大倍数]
	__int64				vsellvolume;//委卖总量[股]
	unsigned int		voip;		//基金模净[*放大倍数，仅基金]
	unsigned int		highlimit;	//涨停价格[*放大倍数]
	unsigned int		lowlimit;	//跌停价格[*放大倍数]	

	//以下为扩展数据
	unsigned int		tradetime;		//交易时间[HHMMSS格式]，例如150001，即15点0分1秒
	unsigned int		nowv;			//分笔成交量，即当前成交量减上一笔成交量
	float					nowa;		//分笔成交额(期货为持仓差)
	unsigned int		outerVol;		//外盘，根据前后两笔数据涨跌关系，将成交量分解为内盘与外盘

	unsigned int		temp[5];		//预留

	CReport10_32()
	{
		::memset(this, 0, sizeof CReport10_32);
	}
	void Init(TCP_ASK_HEAD* pAskHead)
	{
		::memset(this, 0, sizeof CReport10_32);
		askHead = *pAskHead;
	}
};

class CTrace10_33		//向网际风提供逐笔数据
{

public:
	struct TRACE33
	{
		unsigned char	ipushtype;	//推送类型,‘3’，网际风忽略
		unsigned char	code[6];	//商品代码，网际风忽略
		unsigned char	tradetype;	//交易类型，网际风忽略
		unsigned int	tradeno;	//交易序号，网际风忽略
		unsigned int	tradetime;	//交易时间[HHMMSS格式]，例如150001，即15点0分1秒
		unsigned int	price;		//成交价格[*放大倍数]
		__int64			volume;		//成交量[股]
		char			isBuy;		//-1: 与上在笔相比下跌；1:上涨； 2:平盘且上一笔上涨；-2:平盘且上一笔下跌
		unsigned int	temp[2];	//预留
		WORD GetTime()	//转为离早上6点的秒数
		{
			return WORD((tradetime / 10000 - 6) * 3600 + (tradetime % 10000) / 100 * 60 + tradetime % 100);
		}
	};
	TCP_ASK_HEAD  askHead;	//返回申请数据相关信息
	TRACE33	trace33[1];			//可以连接多个数据
	CTrace10_33()
	{
		::memset(this, 0, sizeof CTrace10_33);
	}
	void Init(TCP_ASK_HEAD* pAskHead)
	{
		::memset(this, 0, sizeof CTrace10_33);
		askHead = *pAskHead;
	}
	UINT GetDataLen()
	{
		return (UINT)(offsetof(CTrace10_33, trace33) + askHead.count * sizeof TRACE33);
	}
};

struct QIANLONG_F10INDEX		//钱龙索引记录
{
	char type;			//索引类型(0X00)
	char group;		    //信息分类(0X04，0X14...)
	char market;		//市场类型(0X00)
	int  date;			//年月日(0X1332C61→2013-09-13)
	int  time;			//时分秒(0X00)
	char title[64];		//信息标题
	char filePath[80];	//源文件路径
	int  offset;		//对应资料文件偏移位置，-1表示整个文件
	int  length;		//信息长度，-1表示整个文件
	char code[4][9];	//相关代码，4个相关代码，第一字节存放市场，后8个字节存放股票代码(1 + 000001 + 空格)
	char temp[6];		//未知
	char reserved[50];	//预留
	char checkSum;		//检验码(0)
};

struct QIANLONG_F10HEAD		//钱龙F10索引头
{
	char  mark[8];		//文件标志(QIANLONG)
	char  mainVer;		//主版本号(0X01)
	char  subVer;		//子版本号(0X00)
	WORD  count;		//索引记录数(0X10)
	int   dataLen;		//数据总长度(0X00)
	QIANLONG_F10INDEX f10Index[32];
	QIANLONG_F10HEAD()
	{
		Init();
	}
	int GetHeadLen()		//索引区总长度
	{
		return offsetof(QIANLONG_F10HEAD, f10Index) + count * sizeof QIANLONG_F10INDEX;
	}
	LPCSTR GetFilePath()	//取得文件路径
	{
		f10Index->filePath[79] = 0;
		return f10Index->filePath;
	}
	void Init()
	{
		::memset(this, 0, sizeof QIANLONG_F10HEAD);
		::memmove(this->mark, "NezipF10", 8);
		this->mainVer = 0X01;
		this->subVer  = 0X00;
		this->count   = 0X00;
		this->dataLen = 0X00;
	}
};

#pragma	pack(pop)