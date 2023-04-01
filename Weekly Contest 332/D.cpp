//O(n*n*n)
class Solution {
private:
    bool isSubsequence(string &s, string &t){
        int i = 0, j = 0, n = size(s), m = size(t);
        while(i<n and j<m){
            j += s[i++] == t[j];
        }
        return j==m;
    }
public:
    int minimumScore(string s, string t) {
        int n = size(t);
        int mini = n+1;
        if(isSubsequence(s, t))
            mini = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string n_t = t.substr(0, i) + t.substr(j+1);
                if(isSubsequence(s, n_t)){
                    mini = min(mini, j-i+1);
                }
            }
        }
        return mini;
    }
};

//O(n*n)
class Solution {
private:
    // bool isSubsequence(string &s, string &t){
    //     int i = 0, j = 0, n = size(s), m = size(t);
    //     while(i<n and j<m){
    //         j += s[i++] == t[j];
    //     }
    //     return j==m;
    // }
public:
    int minimumScore(string s, string t) {
        int n = size(t);
        int m = size(s);
        int mini = n;
        vector<int>pref(n, m);
        vector<int>suff(n, -1);

        int s_idx = 0, t_idx = 0;
        while(t_idx<n){
            while(s_idx<m and s[s_idx] != t[t_idx]) s_idx++;
            pref[t_idx++] = s_idx;
            if(s_idx>=m){
                s_idx=m;
            }
            else s_idx++;
        }
        for(int it: pref) cout<<it<<" ";
        cout<<endl;
        t_idx = n-1, s_idx = m-1;
        while(t_idx>=0){
            while(s_idx>=0 and s[s_idx] != t[t_idx]) s_idx--;
            suff[t_idx--] = s_idx;
            if(s_idx<0){
                s_idx = -1;
            }
            else s_idx--;
        }
        for(int it: suff) cout<<it<<" ";


        //baseCase
        // if(isSubsequence(s, t))
        //     mini = 0;
        // if(pref[0]==0 and suff[n-1] == m-1) mini = 0;
        if(pref[n-1]<m and suff[0]>=0) mini = 0;

        for(int i=0; i<n; i++){
            for(int j=n-1; j>=i; j--){
                // string n_t = t.substr(0, i) + t.substr(j+1);
                bool isSubsequence = (i>0 ? pref[i-1] : -1) < (j+1<n ? suff[j+1] : m);
                if(isSubsequence){
                    mini = min(mini, j-i+1);
                }
            }
        }
        return mini;
    }
};

//O(nlog(m))
class Solution {
public:
    bool find(string &s,string &t,int mid) {
        int n=s.size();
        int m=t.size();
        vector<int>left(m,n),right(m,-1);
        for(int i=0,j=0;j<m&&i<n;i++) {
            if(s[i]==t[j]) {
                left[j]=i;
                j++;
            }
        }
        for(int i=n-1,j=m-1;j>=0&&i>=0;i--) {
            if(s[i]==t[j]) {
                right[j]=i;
                j--;
            }
        }
        if(left[m-1]!=n) {
            return true;
        }
        if(right[mid]!=-1||left[m-mid-1]!=n) {
            return true;
        }
        for(int i=1;i+mid<m;i++) {
            if(left[i-1]<right[i+mid]) {
                return true;
            }
        }
        return false;
    }
    int minimumScore(string s, string t) {
        int l=0;
        int r=t.size()-1;
        int ans=t.size();
        while(l<=r) {
            int mid=(l+r)/2;
            if(find(s,t,mid)) {
                ans=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return ans;
    }
};