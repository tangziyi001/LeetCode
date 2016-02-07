// Topological Sort
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
    vi deg;
    vi re;
    vvi all;
    queue<int> qq;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vi ttmp;
        all.assign(numCourses, ttmp);
        deg.assign(numCourses, 0);
        int sz = prerequisites.size();
        for(int i = 0; i < sz; i++){
            all[prerequisites[i].second].push_back(prerequisites[i].first);
            deg[prerequisites[i].first]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(deg[i] == 0) qq.push(i);
        }
        while(!qq.empty()){
            int now = qq.front(); qq.pop();
            re.push_back(now);
            int ssz = all[now].size();
            for(int i = 0; i < ssz; i++){
                deg[all[now][i]]--;
                if(deg[all[now][i]] == 0) qq.push(all[now][i]);
            }
        }
        if(re.size() == numCourses)
            return re;
        else{
            vi emp;
            return emp;
        }
        
    }
};