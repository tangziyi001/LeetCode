// Dutch Flag Algorithm
// If the element belongs to middle, increment left and middle pointer.
// If the element belongs to right, decrease right pointer.
class Solution {
public:
    void myswap(int* a, int* b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void sortColors(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return;
        int p1 = 0;
        int p2 = 0;
        int p3 = sz-1;
        while(p2 <= p3){
            while(p1 < sz && nums[p1] == 0) {p1++;p2++;}
            while(p3 >= p2 && nums[p3] == 2) p3--;
            if(p2 > p3) break;
            if(nums[p2] == 0) {
                cout << "0" << " " << p1 << p2 << endl;
                myswap(&nums[p1],&nums[p2]);
                p1++;p2++;
            }
            else if(nums[p2] == 2){
                cout << "2" << " " << p2 << p3 << endl;
                myswap(&nums[p2],&nums[p3]);
                p3--;
            }
            else p2++;
        }
    }
};