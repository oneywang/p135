#include "stdafx.h"
#include "mysqlwriter.h"
#include <asio/thread.hpp>
MysqlWriter gMysqlWriter;
MysqlDb gDb;
bool MysqlWriter::init(CIniFile &inicfg)
{
	_db_opt._db = inicfg.GetKeyValue("db", "db");
	_db_opt._server = inicfg.GetKeyValue("db", "host");
	_db_opt._port = atoi(inicfg.GetKeyValue("db", "port").c_str());
	_db_opt._clientflags = CLIENT_MULTI_STATEMENTS | CLIENT_MULTI_RESULTS;
	_db_opt._user = inicfg.GetKeyValue("db", "user");
	_db_opt._password = inicfg.GetKeyValue("db", "pwd");

	my_bool autoreconnect = true;
	gDb.options(MYSQL_OPT_RECONNECT, &autoreconnect);
	gDb.options(MYSQL_SET_CHARSET_NAME, "gbk");
	if (!gDb.connect(_db_opt))
	{
		addlog("д���ݿ�����ʧ��");
		return false;
	}
	addlog("���ݿ����ӳɹ�");
	new asio::thread([this]
	{
		addlog("���ݿ�д�߳�����");
		while (true)
		{
			SleepEx(3000,TRUE);
			writeonce();
		}
	});
	return true;
}

void MysqlWriter::writeonce()
{

}
