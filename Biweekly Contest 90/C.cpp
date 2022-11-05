class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int,int>mp;
        int maxi = 0;
        for(int num:nums){
            mp[num%space]++;
            maxi = max(maxi, mp[num%space]);
        }
        int mini = 1e9;
        for(int num:nums){
            if(mp[num%space] == maxi){
                mini = min(mini, num);
            }
        }
        return mini;
    }
};