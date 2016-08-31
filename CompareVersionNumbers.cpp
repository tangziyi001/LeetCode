class Solution {
public:
    int compare(vector<int>& v1, vector<int>& v2){
        int idx1 = 0;
        int idx2 = 0;
        while(idx1 < v1.size() && idx2 < v2.size()){
            if(v1[idx1] > v2[idx2])
                return 1;
            else if(v1[idx1] < v2[idx2])
                return -1;
            idx1++;idx2++;
        }
        while(idx1 < v1.size()){
            if(v1[idx1] > 0) return 1;
            idx1++;
        }
        while(idx2 < v2.size()){
            if(v2[idx2] > 0) return -1;
            idx2++;
        }
        return 0;
    }
    int compareVersion(string version1, string version2) {
        int sz1 = version1.size();
        int sz2 = version2.size();
        int idx1 = 0;
        int idx2 = 0;
        vector<int> v1;
        vector<int> v2;
        for(int i = 0; i < sz1; i++){
            if(version1[i] == '.'){
                string num = version1.substr(idx1, i-idx1);
                v1.push_back(stoi(num));
                idx1 = i+1;
                i = idx1;
            }
        }
        for(int i = 0; i < sz2; i++){
            if(version2[i] == '.'){
                string num = version2.substr(idx2, i-idx2);
                v2.push_back(stoi(num));
                idx2 = i+1;
                i = idx2;
            }
        }
        if(idx1 != sz1){
            v1.push_back(stoi(version1.substr(idx1,sz1-idx1)));
        }
        if(idx2 != sz2){
            v2.push_back(stoi(version2.substr(idx2,sz2-idx2)));
        }
        return compare(v1,v2);
    }
};