class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>>& visited,int dr[],int dc[]){
        visited[r][c] = 1;

        for(int i = 0 ;i<4 ; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[r].size() && !visited[nr][nc] && board[nr][nc] == 'O'){
                dfs(nr,nc,board,visited,dr,dc);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        int dr[] = {-1,0,0,1};
        int dc[] = {0,1,-1,0};

        //boundary checks
        for(int i = 0 ; i<m ; i++){
            if(!visited[0][i] && board[0][i] == 'O'){
                dfs(0,i,board,visited,dr,dc);
            }
        }
        for(int i = 0 ; i<n ; i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                dfs(i,0,board,visited,dr,dc);
            }
        }
        for(int i = 0 ; i<m ; i++){
            if(!visited[n-1][i] && board[n-1][i] == 'O'){
                dfs(n-1,i,board,visited,dr,dc);
            }
        }
        for(int i = 0 ; i<n ; i++){
            if(!visited[i][m-1] && board[i][m-1] == 'O'){
                dfs(i,m-1,board,visited,dr,dc);
            }
        }

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};