class Solution {
private:
    int dir[2][2] = {{1, 0},{0,1}};
    bool dfs(vector<vector<int>>& grid, int r, int c){
        if(r==grid.size()-1 and c == grid[0].size()-1) return true;
        if(r>=grid.size() or c>=grid[0].size()){
            return 0;
        }
        if(grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        bool flag = false;
        for(auto &[dr, dc]: dir){
            int nr = dr+r, nc = dc+c;
            flag = flag or dfs(grid, nr, nc);
        }
        return flag;
    }
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if(dfs(grid, 0, 0) == false) return true;
        grid[0][0] = 1;
        if(dfs(grid, 0, 0) == false) return true;
        return false;
    }
};