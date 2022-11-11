// 2360. Longest Cycle in a Graph
class Solution {
    const static int ACTIVE_NODE = 1;
    const static int EXPLORED_NODE = 2;
private:
    void dfs(vector<int>graph[], int src, vector<int>&vis, vector<int>&height, int depth, int &cycle_len){
        if(vis[src] == ACTIVE_NODE){
            cycle_len = max(cycle_len, depth-height[src]);
            return;
        }
        if(vis[src] == EXPLORED_NODE) return;

        vis[src] = ACTIVE_NODE;
        height[src] = depth;
        for(auto child:graph[src]){
            dfs(graph, child, vis, height, depth+1, cycle_len);
        }
        vis[src] = EXPLORED_NODE;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = size(edges);
        vector<int>graph[n+1];
        vector<int>vis(n,0);
        vector<int>height(n,0);
        for(int i=0;i<n;i++){
            if(edges[i] != -1)graph[i].push_back(edges[i]);
        }
        int res = -1;
        for(int i=0;i<n;i++){
            dfs(graph, i, vis, height, 1, res);
        }
        return res;
    }
};