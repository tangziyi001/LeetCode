// 2D vector's iterator
typedef vector<int> vi;
typedef vector<vi> vvi;
class Vector2D {
public:
    int sz;
    int idx;
    vvi::iterator cur;
    vvi::iterator end;
    int now = 0;
    Vector2D(vector<vector<int>>& vec2d) {
        sz = vec2d.size();
        cur = vec2d.begin();
        end = vec2d.end();
    }

    int next() {
        cout << (*cur)[now] << endl;
        int re = (*cur)[now];
        now++;
        if(now >= (*cur).size()){
            now = 0;
            cur+=1;
        }
        return re;
    }

    bool hasNext() {
        while(cur != end && (*cur).size() == 0)
            cur += 1;
        if(cur == end)
            return false;
        else
            return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */