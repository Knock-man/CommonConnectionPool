#include"pch.h"
#include"Connection.h"
#include"CommonConnectionPool.h"
using namespace std;
//未使用连接池单线程
void single(){
    clock_t begin = clock();
    for(int i=0;i<10000;i++){
        Connection conn;
        char sql[1024] = {0};
        sprintf(sql,"insert into student(name) values('%s')","xiaojie");
        conn.connect("127.0.0.1",3306,"xbj","xbj","xbj");
        conn.update(sql);
    }
    clock_t end = clock();
    cout<< end - begin <<"ms"<<endl;
}
//使用连接池单线程
void singlepool(){
    clock_t begin = clock();

    ConnectionPool *cp = ConnectionPool::getconnectionPool();
    for(int i=0;i<10000;i++){
       shared_ptr<Connection> conn = cp->getConnection();
       char sql[1024] = {0};
       sprintf(sql,"insert into student(name) values('%s')","xiaojie");
       conn->update(sql);
    }
    clock_t end = clock();

    cout<< end - begin <<"ms"<<endl;
}
//使用连接池，4线程
void mutipool(){
   clock_t begin = clock();
   
   thread t1([](){
        ConnectionPool *cp = ConnectionPool::getconnectionPool();
        shared_ptr<Connection> conn = cp->getConnection();
        for(int i=0;i<2500;i++){
       char sql[1024] = {0};
       sprintf(sql,"insert into student(name) values('%s')","xiaojie");
       conn->update(sql);
    }
   });
   thread t2([](){
       ConnectionPool *cp = ConnectionPool::getconnectionPool();
        shared_ptr<Connection> conn = cp->getConnection();
        for(int i=0;i<2500;i++){
       char sql[1024] = {0};
       sprintf(sql,"insert into student(name) values('%s')","xiaojie");
       conn->update(sql);
    }
   });
   thread t3([](){
       ConnectionPool *cp = ConnectionPool::getconnectionPool();
        shared_ptr<Connection> conn = cp->getConnection();
        for(int i=0;i<2500;i++){
       char sql[1024] = {0};
       sprintf(sql,"insert into student(name) values('%s')","xiaojie");
       conn->update(sql);
    }
   });
   thread t4([](){
      ConnectionPool *cp = ConnectionPool::getconnectionPool();
        shared_ptr<Connection> conn = cp->getConnection();
        for(int i=0;i<2500;i++){
       char sql[1024] = {0};
       sprintf(sql,"insert into student(name) values('%s')","xiaojie");
       conn->update(sql);
    }
   });
   t1.join();
   t2.join();
   t3.join();
   t4.join();
    clock_t end = clock();
    cout<< end - begin <<"ms"<<endl;
}
//不使用连接池，4线程
void muti(){
     Connection conn;
     conn.connect("127.0.0.1",3306,"xbj","xbj","xbj");
    clock_t begin = clock();
    
   thread t1([](){
       for(int i=0;i<2500;i++){
            char sql[1024] = {0};
            sprintf(sql,"insert into student(name) values('%s')","xiaojie");
            Connection conn;
            conn.connect("127.0.0.1",3306,"xbj","xbj","xbj");
            conn.update(sql);
        }
   });
   thread t2([](){
      for(int i=0;i<2500;i++){
            char sql[1024] = {0};
            sprintf(sql,"insert into student(name) values('%s')","xiaojie");
            Connection conn;
            conn.connect("127.0.0.1",3306,"xbj","xbj","xbj");
            conn.update(sql);
        }
   });
   thread t3([](){
      for(int i=0;i<2500;i++){
            char sql[1024] = {0};
            sprintf(sql,"insert into student(name) values('%s')","xiaojie");
            Connection conn;
            conn.connect("127.0.0.1",3306,"xbj","xbj","xbj");
            conn.update(sql);
        }
   });
   thread t4([](){
     for(int i=0;i<2500;i++){
            char sql[1024] = {0};
            sprintf(sql,"insert into student(name) values('%s')","xiaojie");
            Connection conn;
            conn.connect("127.0.0.1",3306,"xbj","xbj","xbj");
            conn.update(sql);
        }
   });
   t1.join();
   t2.join();
   t3.join();
   t4.join();
    clock_t end = clock();
    cout<< end - begin <<"ms"<<endl;
}
int main(){
   

    return 0;
    
}