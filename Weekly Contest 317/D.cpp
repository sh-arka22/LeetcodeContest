/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    const static int N = 1e5+1;
    int clockwise[N], anti_clockwise[N];
    int maxH = 0;
    void dfs(TreeNode* root, int h){
        if(!root) return;
        clockwise[root->val] = maxH;
        maxH = max(maxH, h);
        dfs(root->left, h+1);
        dfs(root->right, h+1);
    }
    void reversedfs(TreeNode* root, int h){
        if(!root) return;
        anti_clockwise[root->val] = maxH;
        maxH = max(maxH, h);
        reversedfs(root->right, h+1);
        reversedfs(root->left, h+1);
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int>ans;
        dfs(root,0);
        maxH = 0;
        reversedfs(root,0);
        for(auto q:queries){
            ans.push_back(max(clockwise[q], anti_clockwise[q]));
        }
        return ans;
    }
};