// Find Boundary by binary search
class Solution {
public:
    vector<vector<char>> all;
    int minArea(vector<vector<char>>& image, int x, int y) {
        all = image;
        int rsz = image.size();
        int csz = image[0].size();
        int left = searchCol(0,y,0,rsz,1);
        int right = searchCol(y+1,csz,0,rsz,0);
        int top = searchRow(0,x,left,right,1);
        int bottom = searchRow(x+1,rsz,left,right,0);
        return (right-left)*(bottom-top);
    }
    int searchCol(int i, int j, int top, int bottom, int bol){
        while(i != j){
            int k = top;
            int mid = (i+j)/2;
            while(k < bottom && all[k][mid] == '0') k++;
            if(k < bottom == bol){    // There is '1' within that column.
                j = mid;
            }  
            else
                i = mid+1;
        }
        return i;
    }
    int searchRow(int i, int j, int left, int right, int bol){
        while(i != j){
            int k = left;
            int mid = (i+j)/2;
            while(k < right && all[mid][k] == '0') k++;
            if(k < right == bol){    // There is '1' within that column.
                j = mid;
            }  
            else
                i = mid+1;
        }
        return i;
    }
};