class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = size(words);
        unordered_set<char>st = {'a', 'e', 'i', 'o', 'u'};
        vector<int>arr;
        for(string word: words){
            if(st.count(word.front()) and st.count(word.back())){
                arr.push_back(1);
            }
            else arr.push_back(0);
        }
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        vector<int>res;
        for(auto q: queries){
            res.push_back(arr[q[1]] - (q[0] ? arr[q[0]-1] : 0));
        }
        return res;
    }
};