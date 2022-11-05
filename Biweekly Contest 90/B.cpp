class Solution {
private:
    bool matched(string &a, string &b){
        if(size(a) != size(b)) return false;
        int n = size(a);
        int cnt = 0;
        for(int i = 0; i <n;i++){
            if(a[i]!=b[i] and ++cnt>2) return false;
        }
        return true;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string &q:queries) {
            for(string &d:dictionary) {
                if(matched(q,d)){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};