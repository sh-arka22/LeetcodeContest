// 2386. Find the K-Sum of an Array
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        using ll = long long;
        ll maxSum = 0;
        for(int &x: nums){
            x >= 0 ? maxSum += x : x*=-1;
        }

        sort(begin(nums), end(nums));

        priority_queue<pair<ll,ll>> pq;
        vector<ll>ans;
        ans.push_back(maxSum);
        pq.push({maxSum-nums[0], 0});

        while(size(ans)<k){
            auto [curr, idx] = pq.top();
            pq.pop();
            ans.push_back(curr);
            if(idx+1>=size(nums)) continue;
            pq.push({curr-nums[idx+1], idx+1});
            pq.push({curr-nums[idx+1]+nums[idx], idx+1});
        }
        return ans[k-1];
    }
};