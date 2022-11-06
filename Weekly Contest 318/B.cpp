class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        using ll = long long;
        int n = size(nums);
        set<int>st;
        ll maxi = 0;
        ll sum = 0;
        int l = 0, r = 0;
        while(r<n){
            while(st.count(nums[r]) or r-l+1>k){
                st.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            sum+=nums[r];
            if(r-l+1==k)maxi = max(maxi, sum);
            st.insert(nums[r]);
            r++;
        }
        return maxi;
    }
};