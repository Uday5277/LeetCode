class Solution {
public:
    int helper(vector<vector<int>>& triangle,int i,int j, vector<vector<int>>& dp){
        if(i == triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int down = triangle[i][j] + helper(triangle,i+1,j,dp);
        int diagonal = triangle[i][j] + helper(triangle,i+1,j+1,dp);
        return dp[i][j] = min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return helper(triangle,0,0,dp);
    }
};