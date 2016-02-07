// Alternative solution: use stack to maintain the smaller element
class MinStack {
public:
    vector<int> all;
    vector<int> smallest;
    int idx = 0;
    int small_idx = 0;
    int small = 0;
    void push(int x) {
        if(all.size() == 0){
            all.push_back(x);
            smallest.push_back(0);
            small = x;
            small_idx = 0;
            idx++;
            return ;
        }
        all.push_back(x);
        if(x < small){
            small = x;
            small_idx = idx;
        }
        smallest.push_back(small_idx);
        idx++;
    }

    void pop() {
        if(all.size() == 0) return;
        all.pop_back();
        smallest.pop_back();
        small = all[(*(smallest.end()-1))];
        small_idx = *(smallest.end()-1);
        idx--;
    }

    int top() {
        if(all.size() == 0) return NULL;
        return *(all.end()-1);
    }

    int getMin() {
        cout << *(smallest.end()-1) << endl;
        return all[(*(smallest.end()-1))];
    }
};