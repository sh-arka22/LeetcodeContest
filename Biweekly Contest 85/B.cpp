// 2380. Time Needed to Rearrange a Binary String
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int t = 0;
        int n = size(s);
        while(true){
            bool flag = true;
            for(int i=1;i<n;){
                if(s[i]=='1' and s[i-1]=='0'){
                    swap(s[i], s[i-1]);
                    i+=2;
                    flag = false;
                }
                else i++;
            }
            if(flag) break;
            t++;
        }
        return t;
    }
};