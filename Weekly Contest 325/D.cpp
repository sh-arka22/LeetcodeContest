class Solution {
    
    long power(long x, long y, long p){
        long res = 1; 
        x = x % p;

        while (y > 0){
            if ((y & 1) > 0)
                res = (res * x) % p;
            y = y >> 1; 
            x = (x * x) % p;
        }
        return res;
    }
    
    public int countPartitions(int[] nums, int k) {
        int mod = 1000000007;
        long sum = 0;
        for (int x : nums){
            sum+=x;
        }
        if(sum< 2*k){
            return 0;
        }
        
        int n = nums.length;
        long[][] dp = new long[n+1][k];
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                dp[i+1][j] = dp[i][j];
                if (j>=nums[i]) {
                    dp[i+1][j] += dp[i][j-nums[i]];
                    dp[i+1][j] %= mod;
                }
            }
        }
        long ans = power(2,n,mod);
        
        for (int i = 0; i < k; ++i) {
            ans -= dp[n][i]*2;
            ans %= mod;
            ans += mod;
            ans %= mod;
        }
        return (int)ans;
    }
}