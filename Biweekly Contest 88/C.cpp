// 2425. Bitwise XOR of All Pairings
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        for(int x:nums1){
            mp[x] += (size(nums2));
        }
        for(int x:nums2){
            mp[x] += (size(nums1));
        }

        int ans = 0;
        for(auto &[key,val]:mp){
            val%=2;
        }

        for(auto [key,val]:mp){
            if(val==1){
                ans ^= key;
            }
        }
        return ans;
    }
};