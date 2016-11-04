/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        s+=',';
        stack<NestedInteger> ss;
        NestedInteger re;
        int idx = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[idx] != '-' && (s[idx] < '0' || s[idx] > '9')) idx = i;
            if(s[i] != '-' && (s[i] < '0' || s[i] > '9') && i > idx){
                string num = s.substr(idx, i-idx);
                int nnum = stoi(num);
                //cout << nnum << endl;
                NestedInteger tmp = NestedInteger(nnum);
                re = tmp;
                idx = i+1;
                if(!ss.empty() && !ss.top().isInteger()){
                    ss.top().add(tmp);
                } else {
                    ss.push(tmp);
                }
            }
            if(s[i] == '['){
                ss.push(NestedInteger());
            } else if(s[i] == ']'){
                NestedInteger ni = ss.top(); ss.pop();
                re = ni;
                if(!ss.empty() && !ss.top().isInteger()){
                    ss.top().add(ni);
                }
            }
        }
        return re;
    }
};