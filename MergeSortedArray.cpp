class Solution {
public:
    vector<int> all;
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = 0;
        int i2 = 0;
        while(i1 < m && i2 < n){
            if(nums1[i1] <= nums2[i2]){
                all.push_back(nums1[i1]);
                i1++;
            }
            else{
                all.push_back(nums2[i2]);
                i2++;
            }
        }
        while(i1 < m){
            all.push_back(nums1[i1]);
            i1++;
        }
        while(i2 < n){
            all.push_back(nums2[i2]);
            i2++;
        }
        int sz = all.size();
        for(int i = 0; i < sz; i++){
            nums1[i] = all[i];
        }
    }
};