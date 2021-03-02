#include "../testinlcude.h"
#include "protocol/jsonProtocol.h"

using nirvana::protocol::jsonProtocol;
using nirvana::transport::Ntransport;

class request{
    string xx;
};

void queryXx(string xx);

class response{
    string result;
};

/*
class queryXxClient{
public:
	queryXxClient(shared_ptr<Nprotocol> np):proto(np){}
	void queryXx(string xx){

		proto->writeMessageBegin("queryXx");
    	proto->writeMessageEnd();
    	proto->writeFieldBegin("xx");
    	proto->writeString("Hello world");
    	proto->writeFieldEnd();
    	proto->writeFlush();
	}

private:
	shared_ptr<Nprotocol> proto;
};
*/

/*
response callRpc(request x){
    
}

Nprotocol np(transportSharedPtr);
np.writeMessageBegin("callRpc_string");
np.writeMessageEnd();

np.writeFieldBegin("xx");
np.writeString("test");
np.writeFieldEnd();

np.writeFlush();
*/

int main(){
    logging::log* logger = logging::log::getLogger();
    logger->setLevel(DEBUG);
    NConnectSocket* cs = new NConnectSocket("127.0.0.1", 11234);
    if(cs->connect() == 0){
        cout<<"connect failed: "<<strerror(errno)<<endl;
        return 0;
    }

    NBuffertransport* sendTp = new NBuffertransport(shared_ptr<NioSocket> (cs));
    jsonProtocol jp((shared_ptr<Ntransport>(sendTp)));
    jp.writeMessageBegin("callRpc_string");
    jp.writeMessageEnd();
    jp.writeFieldBegin("HeloWord");
    jp.writeString("Hello world");
    jp.writeFieldEnd();
    jp.writeFlush();
    
    string messageTitle;
    jp.readMessageBegin(messageTitle);
    jp.readMessageEnd();
    cout<<"get response from server: "<<endl;
    jp.readFieldBegin("code");
    int number;
    jp.readInt(number);
    jp.readFieldEnd();
    cout<<"code : "<<number<<endl;

    jp.readFieldBegin("data");
    jp.readInt(number);
    jp.readFieldEnd();
    cout<<"data : "<<number<<endl;

    jp.readFieldBegin("message");
    string rspMessage;
    jp.readString(rspMessage);
    jp.readFieldEnd();
    cout<<"message : "<<rspMessage<<endl;
    //logger->info("exit");
}
