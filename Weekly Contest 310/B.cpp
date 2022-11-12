// 2405. Optimal Partition of String
class Solution {
public:
    int partitionString(string s) {
        set<char>st;
        int cnt = 0;
        for(char c:s){
            if(st.count(c)){
                cnt++;
                st.clear();
            }
            st.insert(c);
        }
        return cnt+1;
    }
};