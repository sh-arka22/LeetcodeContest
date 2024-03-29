class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        
        for (auto q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            mat[r1][c1] += 1;
            if(r2 + 1 < n and c2 + 1 < n) mat[r2 + 1][c2 + 1] += 1; // two times substraction
            if(r2 + 1< n) mat[r2 + 1][c1] -= 1;
            if(c2 + 1 < n) mat[r1][c2 + 1] -= 1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] += (i-1>=0 ? mat[i-1][j] : 0) + (j-1>=0 ? mat[i][j-1] : 0) - (i-1>=0 and j-1>=0 ? mat[i-1][j-1] : 0);
            }
        }
        return mat;
    }
};