class Solution {
public:
    int minimumPartition(string s, int k) {
        long num = 0;
        int cnt = 1;
        for(char c: s){
            num = num * 10 + (c-'0');
            if(num>k){
                cnt ++;
                num = (c-'0');
            }
            if(num>k) return -1;
        }
        return cnt;
    }
};