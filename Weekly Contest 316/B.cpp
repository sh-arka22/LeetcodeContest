class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        int n =size(nums);
        for(int i=0;i<n;i++){
            int gcd = nums[i];
            for(int j = i;j<n;j++){
                gcd = __gcd(gcd, nums[j]);
                if(gcd == k) cnt++;
                if(gcd<k) break;
            }
        }
        return cnt;
    }
};