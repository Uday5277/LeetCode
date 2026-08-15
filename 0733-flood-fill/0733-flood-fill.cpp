class Solution {
public:
    void dfs(int r,int c,int initialColor,vector<vector<int>>& image,vector<vector<int>>& ans,int color,int dr[], int dc[]){
        ans[r][c] = color;

        for(int i = 0 ; i<4 ; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<image.size() && nc>=0 && nc<image[r].size() && image[nr][nc] == initialColor && ans[nr][nc]!=color){
                dfs(nr,nc,initialColor,image,ans,color,dr,dc);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int initialColor = image[sr][sc];
        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,1,-1,0};
        dfs(sr,sc,initialColor,image,ans,color,dr,dc);

        return ans;
    }
};