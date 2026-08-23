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
public:
    void dfs(int& ans, int pathMax, TreeNode* cur){
        if(cur->val >= pathMax){
            ans++;
            pathMax = cur->val;
        }
        // else pathMax = cur->val;
        // cout << cur->val << " " << ans << " " << pathMax << endl;
        if(cur->left) dfs(ans, pathMax, cur->left);
        if(cur->right) dfs(ans, pathMax, cur->right);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 1;
        int pathMax = root->val;
        
        if(root->left) dfs(ans, pathMax, root->left);
        if(root->right) dfs(ans, pathMax, root->right);
        return ans;

    }
};
