#import <string>
#import <iostream>
#import <vector>
using namespace std;
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int sz = strs.size();
        string re;
        for(int i = 0; i < sz; i++){
            int ssz = strs[i].size();
            cout << ssz << endl;
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
    int main(){
    	vector<string> a;
    	a.push_back("as[]");
    	a.push_back("h173rt280");
    	string at = encode(a);
    	cout << at << endl;
    	vector<string> bt = decode(at);
    	for(int i = 0; i < bt.size();i++){
    		cout << bt[i] << endl;
    	}

    	return 0;
    }

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));