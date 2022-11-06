class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int>st;
        for(int num:nums){
            st.insert(num);
            string s = to_string(num);
            reverse(begin(s), end(s));
            int n = stoi(s);
            st.insert(n);
        }
        return st.size();
    }
};