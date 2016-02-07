typedef vector<int> vi;
typedef vector<vi> vvi;
class NumMatrix {
public:
    vvi dp;
    int rsz,csz;
    NumMatrix(vector<vector<int>> &matrix) {
        rsz = matrix.size();
        if(rsz != 0) csz = matrix[0].size();
        vi ttmp(csz+1,0);
        dp.assign(rsz+1,ttmp);
        for(int i = 0; i < rsz; i++){
            for(int j = 0; j < csz; j++){
                dp[i+1][j+1] = matrix[i][j]+dp[i][j+1]+dp[i+1][j]-dp[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(rsz == 0 || csz == 0) return 0;
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);