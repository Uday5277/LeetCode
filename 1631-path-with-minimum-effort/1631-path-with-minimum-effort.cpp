class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>>effort(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        effort[0][0] = 0;

        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,1,-1,0};

        while(!pq.empty()){
            int eff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            for(int i = 0 ; i<4 ; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int newEffort = max(abs(heights[r][c]-heights[nr][nc]),eff);
                    if(effort[nr][nc]>newEffort){
                    effort[nr][nc] = newEffort;
                    pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return effort[m-1][n-1];
    }
};