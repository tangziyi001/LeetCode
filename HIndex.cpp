class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int sz = citations.size();
        int h = 0;
        for(int i = 0; i < sz; i++){
            if(citations[i] >= sz-i) h = max(h,sz-i);
        }
        return h;
    }
};