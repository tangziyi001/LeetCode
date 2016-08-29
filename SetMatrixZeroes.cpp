class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return ;
        int rsz = matrix.size();
        int csz = matrix[0].size();
        set<int> rows;
        set<int> cols;
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto it = rows.begin(); it != rows.end(); it++){
            int row = *it;
            for(int j = 0; j < csz; j++){
                matrix[row][j] = 0;
            }
        }
        for(auto it = cols.begin(); it != cols.end(); it++){
            int col = *it;
            for(int i = 0; i < rsz; i++){
                matrix[i][col] = 0;
            }
        }
    }
};