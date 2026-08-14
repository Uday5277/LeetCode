class Solution {
public:
    void dfs(int node,vector<vector<int>>& adjMat, vector<int>& visited){
        visited[node] = 1;
        for(int i = 0 ; i<adjMat.size() ; i++){
            if(adjMat[node][i] && !visited[i]){
                dfs(i,adjMat,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,0);
        int cnt = 0;
        for(int i = 0 ; i<n ; i++){
            if(!visited[i]){
                cnt++;
                dfs(i,isConnected,visited);
            }
        }
        return cnt;
    }
};