class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int,int>mp;
        int i = 0, j = 0;
        int n = size(nums);
        int pairs = 0;
        while(j<n){
            pairs += mp[nums[j++]]++;
            while(pairs>=k){
                pairs -= --mp[nums[i++]];
            }
            res += i;
        }
        return res;
    }
};