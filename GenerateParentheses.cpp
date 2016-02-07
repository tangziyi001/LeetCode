class Solution {
public:
    vector<string> all;
    int num;
    void rec(string now, int counter,int pos,int left){
        if(pos == 2*num+1){
            cout << now << endl;
            all.push_back(now);
        }
            
        else{
            if(left < num)
                rec(now+"(",counter+1,pos+1,left+1);
            if(counter){
                rec(now+")",counter-1,pos+1,left);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        num = n;
        rec("",0,1,0);
        return all;
    }
};