class Solution {
public:
    int helper(int row,int col,vector<vector<int>>& dp){
        if(row<0 || col<0) return 0;
        if(row == 0 && col == 0) return 1;

        if(dp[row][col]!=-1) return dp[row][col];

        return dp[row][col] = helper(row-1,col,dp) + helper(row,col-1,dp);
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0] = 1;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i == 0 && j == 0) continue;
                int up = (i-1 < 0) ? 0 : dp[i-1][j];
                int left = (j-1 < 0) ? 0 : dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
        // return helper(m-1,n-1,dp);
    }
};