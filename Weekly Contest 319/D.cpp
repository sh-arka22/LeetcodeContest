// 2472. Maximum Number of Non-overlapping Palindrome Substrings
class Solution {
private:
    int n;
    vector<int>dp;
    vector<vector<int>>palindrome;
    vector<vector<int>>computed;
    bool isPalindrome(string &s, int st, int en){
        if(st>=en) return palindrome[st][en] = true;
        if(computed[st][en]) return palindrome[st][en];
        computed[st][en] = true;
        if(s[st] == s[en]){
            palindrome[st][en] = isPalindrome(s, st+1, en-1);
        }
        else palindrome[st][en] = false;
        return palindrome[st][en];
    }
    int recc(string &s, int idx, int k){
        if(idx==n) return 0; 
        int maxi = 0;
        if(dp[idx] != -1) return dp[idx];
        for(int i=idx+k-1;i<n;i++){
            if(isPalindrome(s, idx, i)){
                maxi = max(maxi, recc(s, i+1, k)+1);
            }
        }
        maxi = max(maxi, recc(s, idx+1, k));
        return dp[idx] = maxi;
    }
public:
    int maxPalindromes(string s, int k) {
        n = size(s);
        dp.resize(n+1, -1);
        palindrome.resize(n+k+1, vector<int>(n+k+1, 0));
        computed.resize(n+k+1, vector<int>(n+k+1, 0));
        return recc(s, 0, k);
    }
};