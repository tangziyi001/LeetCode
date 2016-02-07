// The upper bound is n instead of n-1
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size();
        if(sz == 0) return 0;
        int i = 0;
        int j = sz;
        //if(i == j) return citations[i] >= 1 ? 1 : 0;
        while(i != j){
            int mid = (i+j)/2;
            if(citations[mid] >= sz-mid) j = mid;
            else i = mid+1;
        }
        return sz-i;
    }
};