#include "transport/csocket.h"
#include<unistd.h>
#include "transport/socketBase.h"
#include<iostream>

using nirvana::socket::NConnectSocket;
using nirvana::socket::NioSocket;
using namespace std;

int main(){
    NioSocket ns();
    NConnectSocket cs("127.0.0.1", 11234);
    if(cs.connect() == 0){
        cout<<"connect failed: "<<strerror(errno)<<endl;
        return 0;
    }
    string data = "client message";
    const int pageSize = 100;
    //sleep(10);
    cs.write(data, data.size());
    string buf;
    cout<<EWOULDBLOCK<<endl;
    cout<<"read data from socket : size: "<<cs.read(buf, pageSize)<<", data: "<<buf<<endl;
}
