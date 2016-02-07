// Classical Topological Sort
class Solution {
public:
    vector<int> deg;
    vector<vector<int> > all;
    queue<int> qq;
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        deg.assign(numCourses, 0);
        vector<int> ttmp;
        all.assign(numCourses, ttmp);
        int sz = prerequisites.size();
        for(int i = 0; i < sz; i++){
            all[prerequisites[i].first].push_back(prerequisites[i].second);
            deg[prerequisites[i].second]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(deg[i] == 0) qq.push(i);
        }
        int count = 0;
        while(!qq.empty()){
            int now = qq.front();qq.pop();
            count++;
            int sz = all[now].size();
            for(int i = 0; i < sz; i++){
                deg[all[now][i]]--;
                if(deg[all[now][i]] == 0) qq.push(all[now][i]);
            }
        }
        return count == numCourses;
    }
};