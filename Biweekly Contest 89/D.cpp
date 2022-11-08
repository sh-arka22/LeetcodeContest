// 2440. Create Components With Same Value
class Solution {
private:
    vector<int>arr;
    int dfs(vector<int>graph[], int idx, int parr, int tar){
        int val = arr[idx];
        for(int child:graph[idx]){
            if(child == parr) continue;
            val += dfs(graph, child, idx, tar);
        }
        if(val==tar) return 0;
        return val;
    }
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = size(nums);
        vector<int>graph[n];
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            arr.push_back(nums[i]);
        }
        int maxi = 1;
        for(int parts=1;parts<=n;parts++){
            if(sum % parts) continue;
            if(dfs(graph, 0, -1, sum/parts)) continue;
            maxi = max(maxi, parts);
        }
        return maxi-1;
    }
};