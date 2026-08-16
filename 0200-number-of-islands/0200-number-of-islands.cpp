class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid, vector<vector<int>>& visited,int dr[],int dc[]){
        visited[r][c] = 1;
        for(int i = 0 ; i<4 ; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !visited[nr][nc] && grid[nr][nc] == '1'){
                dfs(nr,nc,grid,visited,dr,dc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,1,-1,0};
        int cnt = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(i,j,grid,visited,dr,dc);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};