#include "transport/csocket.h"
#include "transport/socketBase.h"
#include "transport/bufferTransport.h"
#include "transport/NioVoid.h"
#include "gtest/gtest.h"
#include<string>
#include<memory>

#include<iostream>

using nirvana::socket::NioSocket;
using std::string;
using nirvana::socket::NConnectSocket;
using nirvana::transport::NBuffertransport;
using nirvana::xVoid::NioVoid;
using nirvana::transport::NBufTException;
using std::shared_ptr;

int main(){
    NioVoid x;
    string tmp(10, 'a');
    std::cout<<tmp<<std::endl;
    x.read(tmp, 10);
    std::cout<<tmp<<std::endl;
    try{
        NBuffertransport bt(shared_ptr<NioVoid>(new NioVoid()));
        string buf;
        int rSize = 100;
        std::cout<<bt.read(buf, rSize)<<" , read message: [], size:[]"<<buf<<" "<<buf.size()<<std::endl;
    }
    catch(NBufTException &ex){
        std::cout<<"catch bufTransport type error, detail: "<<ex.what()<<std::endl;
    }
}
