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
 
	2.编译：g++ Connection.cpp CommonConnectionPool.cpp main.cpp -lmysqlclient -pthread

	3.运行:	./a.out

线程池压力测试:

    数据量                    未使用连接池                                  使用连接池
    
    1000        单线程:2378665ms   四线程:1003729ms            单线程:100152ms     四线程:50566ms
    
    10000       单线程:20997982ms  四线程:6090911ms            单线程:1032593ms    四线程:229976ms
    
 
