class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0] = 0;

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        while(!q.empty()){
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if(r == m-1 && c == n-1) return d+1;

            for(int i = -1 ; i<=1 ; i++){
                for(int j = -1 ; j<=1 ; j++){
                    if(i == 0 && j == 0) continue;
                    int nr = r+i;
                    int nc = c+j;
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 0 && d+1<dist[nr][nc]){
                        dist[nr][nc] = d+1;
                        q.push({d+1,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};