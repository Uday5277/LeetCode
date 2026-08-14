class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int visited[n][m];
        int freshOranges = 0;
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }else if(grid[i][j] == 1){
                    freshOranges++;
                }
                visited[i][j] = 0;
            }
        }
        int cnt = 0;
        int ans = 0;
        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,1,-1,0};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            ans = max(ans,time);
            q.pop();
            for(int i = 0 ; i<4 ; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1 && visited[nr][nc]!=2){
                    visited[nr][nc] = 2;
                    cnt++;
                    q.push({{nr,nc},time+1});
                }
            }
        }
        if(cnt!=freshOranges) return -1;
        return ans;
    }
};