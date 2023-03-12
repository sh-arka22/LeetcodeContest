class Solution {
public:
    long long minOperations(vector<int>& n1, vector<int>& n2, int k) {
        long long inc = 0, dec = 0;
        for (int i = 0; i < n1.size(); ++i)
            if (n1[i] != n2[i]) {
                if (k == 0 || abs(n1[i] - n2[i]) % k != 0)
                    return -1;
                inc += max(0, (n2[i] - n1[i]) / k);
                dec += max(0, (n1[i] - n2[i]) / k);
            }
        return inc != dec ? -1 : inc;
    }
};