class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int res = 0;
        for(int it: nums) res ^= it;
        return res;
    }
};