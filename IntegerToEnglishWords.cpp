class Solution {
public:
    string re;
    vector<string> rev;
    string name[5] = {"","Thousand","Million","Billion"};
    string digit[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string tenth[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string ten[10] = {"Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        int pos = 0;
        while(num != 0){
            int tmp = num%1000;
            num/=1000;
            int idx = 0;
            if(pos!=0 && tmp != 0)
                rev.push_back(name[pos]);
            pos++;
            if(tmp >= 100){
                string ttmp = to_string(tmp);
                if(ttmp[1] == '1'){
                    rev.push_back(ten[(int)ttmp[2]-(int)'0']);
                }
                else{
                    rev.push_back(digit[(int)ttmp[2]-(int)'0']);
                    rev.push_back(tenth[(int)ttmp[1]-(int)'0']);
                }
                rev.push_back("Hundred");
                rev.push_back(digit[(int)ttmp[0]-(int)'0']);
            }
            else if(tmp >= 10){
                string ttmp = to_string(tmp);
                if(ttmp[0] == '1'){
                    rev.push_back(ten[(int)ttmp[1]-(int)'0']);
                }
                else{
                    rev.push_back(digit[(int)ttmp[1]-(int)'0']);
                    rev.push_back(tenth[(int)ttmp[0]-(int)'0']);
                }
            }
            else if(tmp > 0){
               rev.push_back(digit[tmp]);
            }
        }
        
        for(auto it = rev.end()-1; it >= rev.begin(); --it){
            if(*it != ""){
                if(it != rev.end()-1) re+=" ";
                re+=*it;
            }
        }
        return re;
    }
};