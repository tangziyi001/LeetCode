// Add a header indicating size and separate it with the content with a notation
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int sz = strs.size();
        string re;
        for(int i = 0; i < sz; i++){
            int ssz = strs[i].size();
            re += to_string(ssz);
            re += "|";
            re += strs[i];
        }
        return re;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> re;
        string tmp;
        int sz = s.size();
        int len = 0;
        int ini = 0;
        for(int i = 0; i < sz; i++){
                if(s[i] == '|'){
                    len = stoi(s.substr(ini,i-ini));
                    string tmp = s.substr(i+1, len);
                    ini = i+1+len;
                    i+=len;
                    re.push_back(tmp);
                }
        }
        return re;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));