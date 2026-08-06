/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,TreeNode*>childToParent(TreeNode* root){
        map<TreeNode*,TreeNode*>mp;
        mp[root] = NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    mp[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    mp[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        return mp;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         map<TreeNode*,TreeNode*> mp = childToParent(root);
         queue<TreeNode*>q;
         q.push(target);
         map<TreeNode*,bool>visited;
         visited[target] = true;
         int dist = 0;
         while(!q.empty()){
            int size = q.size();
            if(dist == k) break;
            for(int i = 0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(mp[node] && !visited[mp[node]]){
                    q.push(mp[node]);
                    visited[mp[node]] = true;
                } 
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
            }
            dist++;
         }
         vector<int>ans;
         while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
         }
         return ans;
    }
};