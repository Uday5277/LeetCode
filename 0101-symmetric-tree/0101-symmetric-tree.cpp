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
    bool helper(TreeNode* r1,TreeNode* r2){
        if(r1 == NULL && r2 == NULL) return true;
        if(r1 && !r2) return false;
        if(r2 && !r1) return false;
        bool h1 =  helper(r1->left,r2->right);
        bool h2 = helper(r1->right,r2->left);
        return h1 && h2 && (r1->val == r2->val);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};