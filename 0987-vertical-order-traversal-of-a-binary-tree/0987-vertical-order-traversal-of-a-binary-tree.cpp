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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>>mp;
        queue<pair<int,pair<int,TreeNode*>>>q;
        q.push({0,{0,root}});
        while(!q.empty()){
            TreeNode* node = q.front().second.second;
            int xAxis = q.front().first;
            int level = q.front().second.first;
            q.pop();
            mp[xAxis][level].insert(node->val);
            if(node->left){
                q.push({xAxis-1,{level+1,node->left}});
            }
            if(node->right){
                q.push({xAxis+1,{level+1,node->right}});
            }
        }
        for (auto& hd : mp) {
            vector<int> col;
            for (auto& level : hd.second) {
                col.insert(col.end(), level.second.begin(), level.second.end());
        }
        ans.push_back(col);
    }
        return ans;
    }
};