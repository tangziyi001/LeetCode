class Solution {
public:
        set<int> ss;
        bool isHappy(int n) {
                if(ss.count(n)) return false;
                if(n == 1) return true;
                ss.insert(n);
                int sum = 0;
                while(n != 0){
                        int tmp = n%10;
                        sum += tmp*tmp;
                        n/=10;
                }
                return  isHappy(sum);
        }
};