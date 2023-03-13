class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st(begin(banned), end(banned));
        int cnt = 0;
        int sum = 0;
        for(int i=1;i<=n;i++){
            if(st.count(i)) continue;
            sum += i;
            if(sum>maxSum) break;
            cnt ++;
        }
        return cnt;
    }
};