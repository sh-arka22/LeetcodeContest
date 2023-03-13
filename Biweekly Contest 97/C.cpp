class Solution {
private:
    vector<vector<int>>dp;
    int recc(vector<int>&arr, int idx, int part, int k){
        if(idx >= arr.size()) return 0;
        if(part == 0) return 0;
        if(dp[idx][part] != -1) return dp[idx][part];
        int notPick = recc(arr, idx+1, part, k);
        int nIdx = upper_bound(begin(arr), end(arr), arr[idx]+k) - arr.begin();
        int pick = nIdx - idx;
        pick += recc(arr, nIdx, part-1, k);
        return dp[idx][part] = max(pick, notPick);
    }
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = size(prizePositions);
        dp.resize(n,vector<int>(3,-1));
        return recc(prizePositions, 0, 2, k);
    }
};