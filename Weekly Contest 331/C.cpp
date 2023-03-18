class Solution {
private:
    bool condition(int m, vector<int>&nums, int k){
        int n = size(nums);
        int i = 0;
        while(i<n){
            if(nums[i]<=m){
                i+=2;
                k--;
            }
            else i++;
            if(k == 0) return true;
        }
        return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int n = size(nums);
        int l = *min_element(begin(nums), end(nums));
        int r = *max_element(begin(nums), end(nums));
        int res = r;
        while(l<=r){
            int m =(l+r)/2;
            if(condition(m, nums, k)){
                res = m;
                r = m-1;
            }
            else l = m+1;
        }
        return res;
    }
};