class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& A, int k) {
        auto cmp = [&](auto const & a, auto const & b) {
            return a[k] > b[k];
        };
        sort(A.begin(), A.end(), cmp);
        return A;
    }
};