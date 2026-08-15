class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>ans(image.begin(),image.end());
        queue<pair<pair<int,int>,int>>q;
        q.push({{sr,sc},image[sr][sc]});
        ans[sr][sc] = color;
        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,1,-1,0};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int val = q.front().second;
            q.pop();
            for(int i = 0 ; i<4 ; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == val && ans[nr][nc]!=color){
                    ans[nr][nc] = color;
                    q.push({{nr,nc},image[nr][nc]});
                }
            }
        }
        return ans;
    }
};