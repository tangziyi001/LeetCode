class NumMatrix {
public:
    vector<vector<int> > bit;
    vector<vector<int> > mat;
    int rsz, csz;
    void updateBit(int row, int idx, int val){
        for(; idx <= csz; idx+=(idx&-idx)){
            bit[row][idx] += val;
        }
    }
    int rsq(int row, int idx){
        int sum = 0;
        for(; idx; idx-=(idx&-idx)){
            sum += bit[row][idx];
        }
        return sum;
    }
    int rsq(int row, int left, int right){
        return rsq(row,right)-rsq(row,left-1);
    }
    NumMatrix(vector<vector<int>> &matrix) {
        rsz = matrix.size();
        if(rsz){
            csz = matrix[0].size();
            bit.assign(rsz, vector<int>(1+csz, 0));
        }
        mat = matrix;
        for(int i = 0; i < rsz; i++) for(int j = 0; j < csz; j++) {
            updateBit(i, j+1, matrix[i][j]);
        }
    }

    void update(int row, int col, int val) {
        updateBit(row, col+1, val-mat[row][col]);
        mat[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++){
            sum += rsq(i, col1+1, col2+1);
        }
        return sum;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);