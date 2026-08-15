class Solution {
    private:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& visited,int dr[],int dc[]){
        int n = grid.size();
        int m = grid[0].size();
        visited[r][c] = 1;
        for(int i = 0 ;i<4 ; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc] == 1){
                dfs(nr,nc,grid,visited,dr,dc);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,1,-1,0};

        for(int i = 0 ; i<m ; i++){
            if(!visited[0][i] && grid[0][i] == 1){
                dfs(0,i,grid,visited,dr,dc);
            }
            if(!visited[n-1][i] && grid[n-1][i] == 1){
                dfs(n-1,i,grid,visited,dr,dc);
            }
        }

        for(int i = 0 ; i<n ; i++){
            if(!visited[i][0] && grid[i][0] == 1){
                dfs(i,0,grid,visited,dr,dc);
            }
            if(!visited[i][m-1] && grid[i][m-1] == 1){
                dfs(i,m-1,grid,visited,dr,dc);
            }
        }
        int cnt = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};