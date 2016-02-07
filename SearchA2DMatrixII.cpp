// Clever use of binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rsz = matrix.size();
        if(rsz == 0) return 0;
        int csz = matrix[0].size();
        if(csz == 0) return 0;
        int x = 0;
        int y = csz-1;
        while(x < rsz && y >= 0){
            if(target == matrix[x][y]) return true;
            if(target > matrix[x][y])
                x++;
            else
                y--;
        }
        return false;
    }
};