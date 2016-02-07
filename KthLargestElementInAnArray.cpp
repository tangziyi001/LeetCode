// Quick Sort Style
class Solution {
public:
    vector<int> all;
    int tar;
    int findKthLargest(vector<int>& nums, int k) {
        int sz = nums.size();
        all = nums;
        tar = sz-k;
        cout << tar << endl;
        return qs(0,sz-1);
    }
    int qs(int s, int t){
       int p = partition(s,t); 
       if(p == tar) return all[p];
       if(p < tar) return qs(p+1,t);
       if(p > tar) return qs(s,p-1);
    }
    int partition(int s, int t){
        int pivot = all[t];
        int low = s;
        for(int i = s; i < t; i++){
            if(all[i] <= pivot){
                myswap(&(all[i]), &(all[low]));
                low++;
            }
        }
        myswap(&(all[low]), &(all[t]));
        return low;
    }
    void myswap(int* a, int* b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    
};