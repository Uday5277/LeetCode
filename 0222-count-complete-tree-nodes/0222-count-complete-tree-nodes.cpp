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
    int leftHeight(TreeNode* root){
        int ans = 0;
        while(root){
            ans++;
            root = root->left;
        }
        return ans;
    }
    int rightHeight(TreeNode* root){
        int ans = 0;
        while(root){
            ans++;
            root = root->right;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lHeight = leftHeight(root);
        int rHeight = rightHeight(root);
        if(lHeight == rHeight){
            return (1<<lHeight)-1;
        }else{
           return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};