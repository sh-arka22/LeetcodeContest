class Solution {
private:
    int check(vector<int>&prices, int diff){
        int cnt = 1;
        int prev = prices[0], n = size(prices);
        for(int i=1;i<n;i++){
            if(prices[i]-prev>=diff){
                cnt++;
                prev = prices[i];
            }
        }
        return cnt;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(begin(price), end(price));
        int n = size(price);
        int l = 1, r = price[n-1] - price[0];
        int res = 0;
        while(l<=r){
            int m = (l+r)/2;
            int cnt = check(price, m);
            if(cnt < k){
                r = m-1;
            }
            else {
                res = m;
                l = m+1;
            }
        }
        return res;
    }
};