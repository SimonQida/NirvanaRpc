#include "gtest/gtest.h"
#include<iostream>

using namespace std;

TEST(test, charToString){
    char buf[10] = {0};
    buf[0] = 'a';
    buf[1] = 'b';
    buf[3] = 'c';
    buf[4] = 'e';
    string x(buf, 6);
    cout<<x<<endl;
    EXPECT_EQ(x.size(), 5);
    for(int i =0; i < x.size(); ++i){
        cout<<x[i]<<",";
    }
    // with this , we get a string with content as following:
    // a b /0 c e /0
    cout<<endl;
}
