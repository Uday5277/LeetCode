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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        if(!root) return ans;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long minIndex = q.front().second;
            long long first,last;
            long long width = 0;
            for(long long i = 0 ; i<size ; i++){
                long long updated_index = q.front().second-minIndex;
                if(i == 0) first = updated_index;
                if(i == size-1) last = updated_index;
                TreeNode* node = q.front().first;
                q.pop();
                if(node->left) q.push({node->left,2*updated_index+1});
                if(node->right) q.push({node->right,2*updated_index+2});
            }
            width = last-first + 1;
            ans = max(ans,width);
        }
        return (int)ans;
    }
};