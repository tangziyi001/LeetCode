// Divide and Conquer (Binary Search)
class Solution {
public:
    int sz;
     vector<int> all;
     int peak(int l, int r){
         cout << l << " " << r << endl;
        if(l == sz-1 || (all[l] >= all[r] && l + 1 >= r))
            return l;
        else if(all[l] < all[r] && l+1>=r)
            return r;
        int i = (l+r)/2;
        if(all[i] > all[i+1])
            return peak(l,i);
        else
            return peak(i+1,r);
        
    }
    int findPeakElement(vector<int>& nums) {
        all = nums;
        sz = nums.size();
        if(sz == 1)
            return 0;
        int re = peak(0,sz-1);
        return re;
    }
   
   
};