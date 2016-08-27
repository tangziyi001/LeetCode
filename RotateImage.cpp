class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        queue<int> rec;
        int sz = matrix.size();
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                rec.push(matrix[i][j]);
            }
        }
        for(int j = sz-1; j >= 0; j--){
            for(int i = 0; i < sz; i++){
                matrix[i][j] = rec.front(); rec.pop();
            }
        }
    }
};