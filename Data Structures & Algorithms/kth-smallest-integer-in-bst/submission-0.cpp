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
    void inOrderTraverse(TreeNode* root, vector<int>& cand){
        if(root->left) inOrderTraverse(root->left, cand);
        cand.push_back(root->val);
        if(root->right) inOrderTraverse(root->right, cand);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> cand;
        inOrderTraverse(root, cand);

        return cand[k-1];
    }
};
