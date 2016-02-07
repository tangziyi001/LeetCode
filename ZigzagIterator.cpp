// Use Queue to create new container
class ZigzagIterator {
public:
    queue<int> all;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int s1 = v1.size();
        int s2 = v2.size();
        int sz = max(s1,s2);
        for(int i = 0; i < sz; i++){
            if(i < s1) all.push(v1[i]);
            if(i < s2) all.push(v2[i]);
        }
    }

    int next() {
        int tmp = all.front();
        all.pop();
        return tmp;
    }

    bool hasNext() {
        return (!all.empty());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */