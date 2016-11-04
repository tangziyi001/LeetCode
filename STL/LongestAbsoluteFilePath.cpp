class Solution {
public:
    unordered_map<int,int> mm; // Temporary Length for each level
    int lengthLongestPath(string input) {
        int maxp = 0;
        int idx = 0;
        int level = 0;
        input += '\n';
        int isFile = 0;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '\t'){
                level++; idx = i+1;
                continue;
            }
            if(input[i] == '\n'){
                string now = input.substr(idx,i-idx);
                idx = i+1;
                mm[level] = level == 0 ? now.size() : mm[level-1]+now.size()+1; // One more for slash
                cout << mm[level] << endl;
                if(isFile){
                    maxp = max(maxp, mm[level]);
                    isFile = 0;
                }
                level = 0;
            }
            if(input[i] == '.') isFile = 1;
        }
        return maxp;
    }
};