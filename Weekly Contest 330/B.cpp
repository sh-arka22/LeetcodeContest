// Total ways will be (2^n) - 2
class Solution {
public:
    int mod = 1e9 + 7;
    int mpow(int x,int y){
        int res=1;
        while(y){
            if(y&1) //odd power
                res = ((long)res * x) % mod;
            x = ((long) x * x) % mod;
            y = y/2;
        }
        return res;
    }
    
    int monkeyMove(int n) {
        return (mpow(2,n)-2 + mod) % mod;
    }
};