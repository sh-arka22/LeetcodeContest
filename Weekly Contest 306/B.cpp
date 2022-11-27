// 2374. Node With Highest Edge Score
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        using ll = long long;
        int n = size(edges);
        vector<int>graph[n];
        for(int i=0;i<n;i++){
            graph[edges[i]].push_back(i);
        }
        ll maxi = 0;
        int val;
        for(int i=0;i<n;i++){
            ll curr = 0;
            for(int child:graph[i]){
                curr += child;
            }
            if(maxi < curr){
                maxi = curr;
                val = i;
            }
        }
        return val;
    }
};