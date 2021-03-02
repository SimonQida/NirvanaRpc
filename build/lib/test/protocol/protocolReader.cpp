class request{
    string xx;
};

class response{
    string result;
};

response callRpc(request x){
    
}

Nprotocol np(transportSharedPtr);

string tmp;
np.readMessageBegin(tmp);
np.readMessageEnd();

np.readFieldBegin(tmp);
np.readFieldEnd();
if (tmp == "result"){
    np.readString(tmp);
    resp.result = tmp;
}
