#include "../testinlcude.h"

void toWire32(char* wireData, int number){
    cout<<"number : "<<hex<<number<<endl;
    int mod = 0x00ff;
    for (int i =0; i < sizeof(number); ++i){
        wireData[i] = mod &number;
        cout<< fmt::format("index {} = number ", i)<<hex<< int(mod&number)<<endl;
        number >>= 8;
    }
}

int main(){
    cout<<DEBUG<<endl;
    NConnectSocket cs("127.0.0.1", 11234);
    if(cs.connect() == 0){
        cout<<"connect failed: "<<strerror(errno)<<endl;
        return 0;
    }
    string data = "client message";
    const int pageSize = 100;
    cs.write(data, data.size());
    string buf;
    cout<<"read data from socket : size: "<<cs.read(buf, pageSize)<<", data: "<<buf<<endl;
    int tubeInt = 110;
    char tmp[4];
    toWire32(tmp, tubeInt);
    cout<<fmt::format("tmp data: 0x{}, {}, {}, {}", int(tmp[0]), int(tmp[1]), int(tmp[2]), int(tmp[3]))<<endl;
    cs.write(tmp, 4);
}
