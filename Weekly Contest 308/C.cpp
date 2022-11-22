// 2391. Minimum Amount of Time to Collect Garbage
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last[128] = {};
        int i = 0;
        int res = 0;
        for(string s:garbage){
            for(char c:s){
                last[c] = i;
                res++;
            }
            i++;
        }
        int n = size(travel);
        for(int i=1;i<n;i++){
            travel[i] += travel[i-1];
        }
        for(char c:"GPM"){
            if(!last[c]) continue;
            res += travel[last[c]-1];
        }
        return res;
    }
};