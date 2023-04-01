class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>>nums;
        int n = s.size();

        for (int i = 0; i < s.size(); i++) {
            int curr = 0;
            for (int j = 0; j < min(31, n-i); j++) {
                //"123"->dec => 1, 1*10+2, 12*10+3 -> 123
                curr <<= 1;
                curr += (int) (s[i+j]-'0');

                if (nums.find(curr) == nums.end()) {
                    nums[curr] = {i, i+j};
                }
                else {
                    //"000101"-> 5 and "101"->5
                    if (j < nums[curr][1] - nums[curr][0]) {
                        nums[curr] = {i, i+j};
                    }
                }
            }
        }

        vector<vector<int>>ans;
        for (auto &q : queries) {
            int n = q[0] ^ q[1];
            if (nums.find(n) != nums.end()) {
                ans.push_back(nums[n]);
            }
            else {
                ans.push_back({-1, -1});
            }
        }
        return ans;
    }
};