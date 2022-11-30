// 2484. Count Palindromic Subsequences
class Solution {
private:
    using ll = long long;
    const static ll mod = 1e9+7;
    vector<vector<ll>>dp;
    ll countSubsequences(string &a, string &b, int M, int N){
        for(int m=0;m<=M;m++){
            for(int n=0;n<=N;n++){
                if((m==0 and n==0) or n==0){
                    dp[m][n] = 1;
                    continue;
                }
                if(m==0){
                    dp[m][n] = 0;
                    continue;
                }
                ll cnt = 0;
                cnt = (cnt%mod + dp[m-1][n]%mod)%mod;
                if(a[m-1] == b[n-1]){
                    cnt = (cnt%mod + dp[m-1][n-1]%mod)%mod;
                }
                dp[m][n] = cnt;
            }
        }
        return dp[M][N];
    }
public:
    int countPalindromes(string s) {
        vector<string>allStrings;
        
        for(char i = '0';i<='9';i++){
            for(char j='0';j<='9';j++){
                for(char k='0';k<='9';k++){
                    string palindrome = "";
                    vector<char>v={i,j,k,j,i};
                    for(char c:v) palindrome += c;
                    allStrings.push_back(palindrome);
                }
            }
        }
        ll ans = 0;
        dp.resize(s.size()+1, vector<ll>(6,0));
        for(string ss: allStrings){
            ans = (ans%mod + countSubsequences(s, ss, s.size(), ss.size())%mod)%mod;
        }
        return ans;
    }
};