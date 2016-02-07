// Remember to use n-1 instead of n
class Solution {
public:
    string re;
    string convertToTitle(int n) {
        while(n != 0){
            n--;
            int tmp = n%26;
            re+=(char)(tmp+(int)'A');
            n/=26;
        }
        reverse(re.begin(),re.end());
        cout << re << endl;
        return re;
    }
};