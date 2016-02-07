// Backtracking. Distinguish integer and string.
class Solution {
public:
    vector<vector<char> > nums;
    vector<string> re;
    int sz;
    void rec(int pos, string now, string digits){
        if(pos == sz) re.push_back(now);
        else{
            int ssz = nums[(int)digits[pos]-(int)'0'].size();
            for(int i = 0; i < ssz; i++){
                rec(pos+1, now+nums[(int)digits[pos]-(int)'0'][i],digits);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<char> ttmp;
        nums.assign(10,ttmp);
        sz = digits.size();
        if(sz == 0) return re;
        for(int i = 2; i <= 6; i++){
            for(int j = (i-2)*3; j < (i-2)*3+3; j++){
                nums[i].push_back((char)((int)'a'+j));
            }
        }
        for(int j = (int)'p'; j < (int)'p' + 4; j++){
            nums[7].push_back((char)j);
        }
        for(int j = (int)'t'; j < (int)'t' + 3; j++){
            nums[8].push_back((char)j);
        }
        for(int j = (int)'w'; j < (int)'w' + 4; j++){
            nums[9].push_back((char)j);
        }
        rec(0,"",digits);
        return re;
    }
};