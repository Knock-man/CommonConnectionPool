#CommonConnectionPool

文件介绍：

	Connection.h Connection.cpp 数据库操作文件
 
	CommonConnectionPool.h CommonConnectionPool.cpp 线程池操作文件
 
	pch.h 公用头文件
 
	public.h 日志文件
 
	mysql.cnf 配置文件
 
	main.cpp 测试文件
 
使用说明:

	1.修改mysql.cnf配置文件
 
	2.运行：g++ Connection.cpp CommonConnectionPool.cpp main.cpp -lmysqlclient -pthread
 
