// Use a stack to keep the idx of all bars in increasing sequence.
// If the current bar is lower than the bar on top of the stack, compute the area from that bar to the idx just after the idx of the second top of the bar with the height of the bar on top of the stack. The reason is that all the bars between the top of the stack and the second top of the stack should all be higher than the bar on top of the stack right now; the bar between the current bar and the bar on top of the stack should also be higher than the bar on top of the stack. And that area is the largest area we can get by using the height of the bar on top of the stack.
class Solution {
public:
    stack<int> ss;
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        int i = 0;
        int maxp = 0;
        while(i < sz){
            if(ss.empty() || heights[i] >= heights[ss.top()])
                ss.push(i++);
            else{
                int topIdx = ss.top();ss.pop();
                maxp = max(maxp, heights[topIdx]*(ss.empty()?i:(i-ss.top()-1)));
            }
        }
        while(!ss.empty()){
            int topIdx = ss.top();ss.pop();
            maxp = max(maxp, heights[topIdx]*(ss.empty()?i:(i-ss.top()-1)));
        }
        return maxp;
    }
};