namespace nirvana{ namespace utils{
    string printBuf(const char* bufData, int len){
        string bufShowData;
        for(int i =0; i < len; ++i){
            if(bufData[i] == '\0'){
                bufShowData.append("\\0");
            }
            else{
                bufShowData.push_back(bufData[i]);
            }
            bufShowData.push_back(' ');
        }
        bufShowData.pop_back();
        return bufShowData;
    }

    string printBuf(const string& bufData, int len){
        string bufShowData;
        for(int i =0; i < len; ++i){
            if(bufData[i] == '\0'){
                bufShowData.append("\\0");
            }
            else{
                bufShowData.push_back(bufData[i]);
            }
            bufShowData.push_back(' ');
        }
        bufShowData.pop_back();
        return bufShowData;
    }
}}

