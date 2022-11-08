// 2439. Minimize Maximum of Array
class Solution {
private:
    bool isPossible(const vector<int>&num, int tar){
        using ll = long long int;
        vector<ll>nums(begin(num), end(num));
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>tar) return false;
            ll diff = (ll)tar-(ll)nums[i-1];
            nums[i-1]+=diff;
            nums[i]-=diff;
        }
        return nums[n-1]<=tar;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int N = 1e9;
        int ans = 0;
        int l = 0, r =  N;

        while(l<=r){
            int m = (l+r)>>1;
            if(isPossible(nums, m)){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};