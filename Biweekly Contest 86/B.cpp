class Solution {
private:
    bool baseConvertor(int num, int base){
        string res = "";
        while(num){
            res += (to_string(num%base));
            num /= base;
        }
        string tmp = res;
        reverse(begin(res), end(res));
        return res == tmp;
    }
public:
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            if(!baseConvertor(n, i))
                return false;
        }
        return 1;
    }
};