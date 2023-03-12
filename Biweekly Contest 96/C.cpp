class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++) a[i] = {nums2[i], nums1[i]};
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        long long ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> p;
        for(int i=0;i<n;i++){
            p.push(a[i].second);
            sum += a[i].second;
            if(i >= k - 1) {
                ans = max(ans, a[i].first * sum);
                sum -= p.top();                
                p.pop();
            }
        }
        return ans;
    }
};