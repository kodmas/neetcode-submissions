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
    bool validBSTdfs(TreeNode* node, int low, int high){
        bool valid = (node->val < high) && (node->val > low);
        // cout << low << " " << node->val << " " << high << endl;
        bool left = true;
        bool right = true;
        if(node->left) left = validBSTdfs(node->left, low, node->val);
        if(node->right) right = validBSTdfs(node->right, node->val, high);

        return valid && left && right;
    }
    
    bool isValidBST(TreeNode* root) {
        int low = -1000000000;
        int high = 1000000000;
        
        return validBSTdfs(root, low, high);
    }
};
