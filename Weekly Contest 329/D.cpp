class Solution {
private:
    int *dp;
    vector<vector<int>>count;
    int solve(vector<int>& nums, int k, int idx){
        if(idx >= size(nums)) return 0;
        if(dp[idx] != -1) return dp[idx];
        int res = INT_MAX;
        for(int i=idx; i<size(nums); i++){
            int curr = k + count[idx][i] + solve(nums, k, i+1);
            res = min(res, curr);
        }
        return dp[idx] = res;
    }
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        dp = new int[n];
        fill(dp, dp+n, -1);
        count = vector<vector<int>>(n, vector<int>(n));
        for(int i = 0; i < n; ++i) {
            vector<int> temp(n);
            int len = 0;
            for(int j = i; j < n; ++j) {
                temp[nums[j]]++; 
                if(temp[nums[j]] == 2) len+=2; 
                else if(temp[nums[j]] > 2) len++; 
                count[i][j] = len;
            }
        }
        return solve(nums, k, 0);
    }
};