// 2438. Range Product Queries of Powers
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>nums;
        for(int i=0;i<=31;i++){
            if(n&(1<<i)){
                int x = 1<<i;
                nums.push_back(x);
            }
        }
        using ll = long long;
        ll prod = 1;
        vector<int>ans;
        for(auto q:queries){
            int l = q[0], r = q[1];
            for(int i=l;i<=r;i++){
                prod = (prod * nums[i])%1000000007;
            }
            ans.push_back(prod);
            prod = 1;
        }
        return ans;
    }