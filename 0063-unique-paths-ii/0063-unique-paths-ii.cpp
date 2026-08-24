class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid,int row,int col,vector<vector<int>>& dp){
        if(row == 0 && col == 0 && obstacleGrid[row][col] == 0) return 1;
        if(row<0 || col<0 || obstacleGrid[row][col] == 1) return 0;

        if(dp[row][col]!=-1) return dp[row][col];

        return dp[row][col] = helper(obstacleGrid,row-1,col,dp) + helper(obstacleGrid,row,col-1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(obstacleGrid,m-1,n-1,dp);
    }
};