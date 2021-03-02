#include "transport/csocket.h"
#include "transport/socketBase.h"
#include "transport/bufferTransport.h"
#include "transport/NioVoid.h"
#include "gtest/gtest.h"
#include<string>
#include<memory>
#include<nlohmann/json.hpp>
#include<iostream>

using nirvana::socket::NioSocket;
using std::string;
using nirvana::socket::NConnectSocket;
using nirvana::transport::NBuffertransport;
using nirvana::xVoid::NioVoid;
using nirvana::transport::bufSize;
using json = nlohmann::json;
using std::cout;
using namespace std;
using std::endl;

TEST(THIRD_PARTY_JSON_LIB, complier_test){
    json j;
    cout<<"empty json: "<<j.dump()<<endl;
    j["pi"] = 1.2;
    j["test"] = {{"echo", 1}, {"keep-alive", "asf"}};
    j["xx"] = "Hello world";
    cout<<j.dump(4)<<endl;
    EXPECT_EQ(j["pi"], 1.2);
    EXPECT_EQ(j["xx"], "Hello world");
    
    j.clear();
    cout<<"cleared json: "<<j.dump()<<endl;
}
