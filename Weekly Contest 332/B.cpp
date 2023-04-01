class Solution {
private:
    long long countSmaller(vector<int>&nums, int val){
        int n = size(nums);
        long long pairs = 0;
        for(int i=0 ,j = n-1; j > i; i++){
            while(i<j and nums[i]+nums[j]>val) j--;
            pairs += (j-i);
        }
        return pairs;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        return countSmaller(nums, upper) - countSmaller(nums, lower-1);
    }
};