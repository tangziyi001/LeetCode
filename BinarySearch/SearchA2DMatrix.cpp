class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rsz = matrix.size();
        if(rsz == 0) return false;
        int csz = matrix[0].size();
        if(csz == 0) return false;
        int sz = rsz*csz;
        int i = 0, j = sz-1;
        while(i <= j){
            int mid = (i+j)/2;
            int val = matrix[mid/csz][mid%csz];
            if(val == target) return true;
            if(val > target) j = mid-1;
            else i = mid+1;
        }
        return false;
    }
};