// 2385. Amount of Time for Binary Tree to Be Infected
class Solution {
public:
    vector<int> al[100001] = {};
    int visited[100001] = {}, res = 0;
    void populate(TreeNode* n) {
        for (auto ch : {n->left, n->right})
            if (ch != nullptr) {
                al[n->val].push_back(ch->val);
                al[ch->val].push_back(n->val);
                populate(ch);
            }
    }
    int amountOfTime(TreeNode* root, int start) {
        populate(root);
        vector<int> q{start};
        while (!q.empty()) {
            vector<int> q1;
            for (int i : q) {
                visited[i] = true;
                for (auto j : al[i])
                    if (!visited[j])
                        q1.push_back(j);
            }
            swap(q, q1);
            ++res;
        }
        return res - 1;
    }
};