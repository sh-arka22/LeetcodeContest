class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = size(pref);
        vector<int>ans;
        int x = pref[0];
        ans.push_back(x);
        for(int i=1;i<n;i++){
            ans.push_back(x^pref[i]);
            x = x^ans.back();
        }
        return ans;
    }
};