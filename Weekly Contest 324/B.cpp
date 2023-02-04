class Solution {
public:
    int find(int n, int i, int j, bool b){ 
        if(n <= i) return n;
        if(n%i == 0) {
            return i + find(n/i, i, j, b);
        }
        int t = 0;
        if(i == 2) t = 3;
        else{
            if(b) { t = j*6+1; j++; }
            else t = j*6-1;
            b = !b;
        }
        return find(n, t, j, b );
    }
    int smallestValue(int n) {
        while(1){
            int t = find(n, 2, 1, false);
            if(t == n) return n;
            n = t;
        }
        return 0;
    }
};