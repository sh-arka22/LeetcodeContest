// 2470. Number of Subarrays With LCM Equal to K
class Solution {
private:
    int Lcm(long long a, long long b){
        return (a*b)/__gcd(a,b);
    }
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = size(nums);
        using ll = long long;
        int ans = 0;
        for(int i=0;i<n;i++){
            int a = nums[i];
            for(int j=i;j<n;j++){
                int lcm = Lcm((ll)a,(ll)nums[j]);
                if(lcm==k) ans++;
                a = lcm;
            }
        }
        return ans;
    }
};