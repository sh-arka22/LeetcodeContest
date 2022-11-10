// 2429. Minimize XOR
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int noOfBits = 0;
        while(num2){
            if(num2&1){
                noOfBits++;
            }
            num2>>=1;
        }
        vector<int> bits1(32,0),bits2(32,0);
        int pos=0;
        while(num1){
            if(num1&1){
                bits1[pos]++;
            }
            pos++;
            num1>>=1;
        }
        for(int i=31;i>=0;i--){
            if(bits1[i] && noOfBits){
                noOfBits--;
                bits2[i]++;
            }
        }
        for(int i=0;i<32;i++){
            if(bits1[i]==0 && noOfBits){
                noOfBits--;
                bits2[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(bits2[i]){
                ans+=pow(2,i);
            }
        }
        return ans;
    }
};