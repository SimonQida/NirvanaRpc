class request{
    string xx;
};

class response{
    string result;
};

response callRpc(request x){
    
}

Nprotocol np(transportSharedPtr);
np.writeMessageBegin("callRpc_string");
np.writeMessageEnd();

np.writeFieldBegin("xx");
np.writeFieldEnd();

np.writeString("test");
np.writeFlush();
