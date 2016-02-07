typedef vector<int> vi;
class MedianFinder {
public:
    priority_queue<int, vi, greater<int>> gp;
    priority_queue<int, vi, less<int>> sp;
    // Adds a number into the data structure.
    void addNum(int num) {
        if(gp.empty() && sp.empty()){
            sp.push(num);
        }
        else{
            if(num >= sp.top())
                gp.push(num);
            else
                sp.push(num);
        }
        if(gp.size() > sp.size() + 1){
            sp.push(gp.top());
            gp.pop();
        }
        if(sp.size() > gp.size() + 1){
            gp.push(sp.top());
            sp.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if((gp.size() + sp.size()) % 2 == 0)
            return (double)(gp.top() + sp.top())/2;
        else
            return (gp.size() > sp.size() ? gp.top() : sp.top());
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();