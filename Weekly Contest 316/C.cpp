class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        using ll = long long;
        ll n = size(nums);
        vector<array<ll, 2>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({nums[i], cost[i]});
        }
        sort(begin(v), end(v));

        ll sum = accumulate(begin(cost), end(cost), 0ll);

        int median;
        ll total = 0;
        int i = 0;
        while (total <= (sum - 1) / 2 and i < n)
        {
            total += ((ll)v[i][1]);
            median = v[i][0];
            i++;
        }
        ll count = 0;
        for (int i = 0; i < n; i++)
        {
            count = count + ((ll)v[i][1] * abs((ll)median - (ll)v[i][0]));
        }
        return count;
    }
};