class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = size(nums);
        long long tot = 0;
        vector<int>dp(n, 0);
        for(int i=0;i<n;i++){
            int inc = 0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    inc++;
                    tot += dp[j];
                }
                else if(nums[i]<nums[j]){
                    dp[j] += inc;
                }
            }
        }
        return tot;
    }
};