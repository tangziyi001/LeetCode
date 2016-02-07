// DFS Graph Clone. Use an array of pointers to record the existed node within the cloned graph.
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode* mark[100000];
    UndirectedGraphNode* head;
    void dfs(UndirectedGraphNode* now, UndirectedGraphNode* node){
        int sz = (node->neighbors).size();
        for(int i = 0; i < sz; i++){
            UndirectedGraphNode* nxt = node->neighbors[i];
            if(mark[nxt->label+50000] == NULL){
                UndirectedGraphNode* newone = new UndirectedGraphNode(nxt->label);
                mark[nxt->label+50000] = newone;
                dfs(newone, nxt);
            }
            now->neighbors.push_back(mark[nxt->label+50000]);
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return head;
        head = new UndirectedGraphNode(node->label);
        mark[head->label+50000] = head;
        dfs(head,node);
        return head;
    }
};