#include"Connection.h"
#include"public.h"
#include"pch.h"    
using namespace std;
// 数据库操作类

    // 初始化数据库连接
    Connection::Connection()
    {
        _conn = mysql_init(nullptr);
    }

    // 释放数据库连接资源
    Connection::~Connection()
    {
        if (_conn != nullptr)
        mysql_close(_conn);
    }

     // 连接数据库
    bool Mysql::connect(string ip, unsigned short port, string user, string password,string dbname)
    {
        MYSQL *p = mysql_real_connect(_conn,ip.c_str(),user.c_str(),password.c_str(),dbname.c_str(),port,nullptr,0);
        if(p == nullptr)
        {
            return false;
        }
        //C和C++代码默认的编码字符是ASCII，如果不设置，从mysql拉下来的中文显示 ?
        mysql_query(_conn,"set names gbk");
        return true;
    }

    // 更新操作 insert、delete、update
    bool Connection::update(string sql)
    {
        if (mysql_query(_conn, sql.c_str()))
        {
            LOG("更新失败:" + sql);
            return false;
        }
        return true;
    }

    // 查询操作 select
    MYSQL_RES* Connection::query(string sql)
    {
        if (mysql_query(_conn, sql.c_str()))
        {
            LOG("查询失败:" + sql);
            return nullptr;
        }
        return mysql_use_result(_conn);
    }
    //刷新一下连接起始的空闲时间点
    void Connection::refreshAliveTime(){
        _alivetime = clock();
    }
    //返回存活的时间段
    clock_t Connection::getAlieTime() const{
        return clock() - _alivetime;

    }
