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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int cnt = 0;
        TreeNode* curr = root;
        while(curr){
            if(curr->left != NULL){
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right == curr){
                    cnt++;
                    if(cnt == k) {
                ans = curr->val;
            }
                    prev->right = NULL;
                    curr = curr->right;
                }else{
                    prev->right = curr;
                    curr = curr->left;
                }

            }else{
                cnt++;
                if(cnt == k) {
                ans = curr->val;
            }
                curr = curr->right;
            }
        }
        return ans;
    }
};