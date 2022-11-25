// 2471. Minimum Number of Operations to Sort a Binary Tree by Level
class Solution {
private:
    int minSwaps(vector<int>&nums){
        int n = size(nums);
        vector<array<int,2>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(begin(v), end(v));
        int cnt = 0;
        for(int i=0;i<n;i++){
            while(i != v[i][1]){
                swap(v[i], v[v[i][1]]);
                cnt++;
            }
        }
        return cnt;
    }
public:
    int minimumOperations(TreeNode* root) {
        deque<TreeNode*>que;
        que.push_back(root);
        int ans = 0;
        
        while(que.size()){
            int sz = que.size();
            vector<int>tmp;
            while(sz--){
                auto top = que.front();
                que.pop_front();
                tmp.push_back(top->val);
                if(top->left)
                    que.push_back(top->left);
                if(top->right)
                    que.push_back(top->right);
            }
            ans += minSwaps(tmp);
        }
        return ans;
    }
};