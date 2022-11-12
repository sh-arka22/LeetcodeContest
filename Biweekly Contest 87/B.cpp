// 2410. Maximum Matching of Players With Trainers
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(begin(p), end(p));
        sort(begin(t), end(t));
        
        int n = p.size(), m = t.size();
        
        int i = 0, j=0;
        int cnt = 0;
        while(i<n and j<m){
            if(p[i]<=t[j]){
                i++,j++;
                cnt++;
            }
            else j++;
        }
        return cnt;
    }
};