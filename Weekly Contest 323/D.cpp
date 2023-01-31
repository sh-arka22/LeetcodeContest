class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>> &grid, set<array<int,3>> &mp, int &val, int x, int y, vector<vector<int>> &vis) {
        if (x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size() or vis[x][y] == 1)
            return 0;
        if (grid[x][y] >= val) {
                mp.insert({grid[x][y], x, y});
                vis[x][y] = -1;
            return 0;
        }
        int sum = 1;
        vis[x][y] = 1;
        for (int i = 0; i < dir.size(); i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            sum += dfs(grid, mp, val, nx, ny, vis);
        }
        return sum;
    }
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
        vector<pair<int, int>> v;
        for (int i = 0; i < queries.size(); i++) {
            v.push_back({queries[i], i});
        }
        sort(v.begin(), v.end());
        auto cmp = [&](array<int,3>lhs, array<int,3>rhs){
            if(lhs[0] != rhs[0])
                return lhs[0] < rhs[0];
            if(lhs[1] != rhs[1])
                return lhs[1]<rhs[1];
            return lhs[2]<rhs[2];
        };
        set<array<int, 3>, decltype(cmp)> mp(cmp);
        set<array<int, 3>> tmp;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        mp.insert({grid[0][0], 0, 0});
        vis[0][0] = -1;
        vector<int> ans(v.size());
        int prv = 0, curr;
        for (int i = 0; i < queries.size(); i++) {
            curr = 0;
            auto j = mp.begin();
            for (; j != mp.end(); j++) {
                if ((*j)[0] < v[i].first) {
                    curr += dfs(grid, tmp, v[i].first, (*j)[1], (*j)[2], vis);
                    mp.erase(j);
                }
                else
                    break;
            }
            for (auto &j : tmp) {
                mp.insert(j);
            }
            tmp.clear();
            ans[v[i].second] = (curr + prv);
            prv += curr;
        }
        return ans;
    }
};