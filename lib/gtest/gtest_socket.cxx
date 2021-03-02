#include "transport/csocket.h"
#include "transport/socketBase.h"
#include "transport/bufferTransport.h"
#include "transport/NioVoid.h"
#include "gtest/gtest.h"
#include<string>
#include<memory>

using nirvana::socket::NioSocket;
using std::string;
using nirvana::socket::NConnectSocket;
using nirvana::transport::NBuffertransport;
using nirvana::xVoid::NioVoid;
using nirvana::transport::bufSize;
using namespace std;

TEST(BUFTRANSPORT_SET, reset_clear){
    NBuffertransport bt(shared_ptr<NioVoid>(new NioVoid()), "reset_clear");
    string buf;
    int rSize = 100;
    bt.read(buf, rSize);
    EXPECT_NE(bt.isClear(), 0);

    bt.reset();
    EXPECT_EQ(bt.isClear(), 0);
}

TEST(BUFREAD, sizeTaste){
    NBuffertransport bt(shared_ptr<NioVoid>(new NioVoid()), "readTaste");
    string buf;
    int rSize = 100;
    EXPECT_EQ(bt.read(buf, rSize), rSize);

    bt.reset();
    //toggle next readFlush by multi-callRead
    for(int i =0; i < bufSize/rSize + 1 ; ++i){
        EXPECT_EQ(bt.read(buf,rSize), rSize);
    }
    
    bt.reset();
    //toggle larger than bufSize callRead
    EXPECT_EQ(bt.read(buf, bufSize+1), bufSize+1);

}

TEST(BUFWRITE, writeTaste){
    NBuffertransport bt(shared_ptr<NioVoid>(new NioVoid()), "writeTaste");
    int wSize = 100;
    string buf(wSize, 'a');
    EXPECT_EQ(bt.write(buf), wSize);

    bt.reset();
    //toggle next writeFlush by multi-callWrite
    for(int i =0; i < bufSize/wSize + 1 ; ++i){
        EXPECT_EQ(bt.write(buf), wSize);
    }
    
    bt.reset();
    //toggle larger than bufSize callWrite
    EXPECT_EQ(bt.write(string(bufSize+1, 'b')), bufSize+1);
}
