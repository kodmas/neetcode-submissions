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
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0];
    }
    vector<int> dfs(TreeNode* root){
        if(!root) return {1, 0};
        vector<int> leftres = dfs(root->left);
        vector<int> rightres = dfs(root->right);
        
        int bal;
        if(abs(leftres[1] - rightres[1]) <= 1) bal = 1;
        else bal = 0;
        int res = leftres[0] & rightres[0] & bal;

        return {res, max(leftres[1], rightres[1])+1};
    }
};
