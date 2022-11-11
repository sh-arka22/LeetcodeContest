// 2414. Length of the Longest Alphabetical Continuous Substring
class Solution {
public:
    int longestContinuousSubstring(string s) {
        char prev = s[0];
        int n = s.size();
        int len = 1;
        int maxi = 0;
        for(int i=1;i<n;i++){
            if(s[i]-prev == 1){
                len++;
                prev = s[i];
                maxi = max(maxi, len);
            }
            else{
                maxi = max(maxi, len);
                len = 1;
                prev = s[i];
            }
        }
        maxi = max(maxi, len);
        return maxi;
    }
};