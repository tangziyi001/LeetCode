// Topological Sort
#import <string>
#import <map>
#import <queue>
typedef vector<vector<int> > vvi;
typedef vector<int> vi;

map<char,int> strint;
vector<char> intstr;
vector<int> degree;
vvi all;
queue<int> qq;
string re = "";
class Solution {
public:
    string alienOrder(vector<string>& words) {
        strint.clear();
        intstr.clear();
        degree.clear();
        all.clear();
        re = "";
        int sz = words.size();
        int idx = 0;
        for(int i = 0; i < sz; i++){
            string tmp = words[i];
            int len = tmp.size();
            for(int j = 0; j < len; j++){
                if(strint.find(tmp[j]) == strint.end()){
                    strint[tmp[j]] = idx++;
                    intstr.push_back(tmp[j]);
                    vi ttmp;
                    all.push_back(ttmp);
                    degree.push_back(0);
                }
               
            }
            if(i > 0){
                int minsz = min(words[i-1].size(),words[i].size());
                for(int j = 0; j < minsz; j++){
                     if(words[i-1][j] != words[i][j]){
                            cout << words[i-1][j] << words[i][j] << endl;
                            all[strint[words[i-1][j]]].push_back(strint[words[i][j]]);
                            degree[strint[words[i][j]]] += 1;
                            break;
                    }
                }
               
            }
        }
        
        
        int total = strint.size();
        for(int i = 0; i < total; i++){
            if(degree[i] == 0)
                qq.push(i);
        }
        while(!qq.empty()){
                int now = qq.front();qq.pop();
                cout << intstr[now] << endl;
                re+=(intstr[now]);
                int sz = all[now].size();
                for(int i = 0; i < sz; i++){
                    int tmp = all[now][i];
                    degree[tmp]--;
                    if(degree[tmp] == 0)
                        qq.push(tmp);
                }
        }
        cout << re.size() << endl;
        if(re.size() < total)
            re = "";
        return re;
        
    }
    
};