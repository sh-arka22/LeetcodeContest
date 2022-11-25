// 2381. Shifting Letters II
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = size(s);
        vector<int>pref(n+1,0);
        for(auto i :shifts){
            int dir = i[2];
            pref[i[0]] += (dir == 1 ? 1 : -1);
            pref[i[1]+1] -= (dir == 1 ? 1 : -1);
        }
        string res = "";
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += pref[i];
            while(sum<0) sum+=26;
            int ch = (s[i]-'a' + sum)%26;
            res += (char)('a'+ch);
        }
        return res;
    }
};