class Solution {
private:
    bool bfs(int node,vector<vector<int>>& graph,vector<int>& visited){
        visited[node] = 0;
        queue<pair<int,int>>q;
        q.push({node,0});
        while(!q.empty()){
            int v = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int& i:graph[v]){
                if(visited[i] == -1){
                    visited[i] = col == 0 ? 1 : 0;
                    q.push({i,visited[i]});
                }else if(visited[i] == col){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,-1);

        for(int i = 0 ; i<n ; i++){
            if(visited[i] == -1){
                if(bfs(i,graph,visited) == false) return false;
            }
        }
        return true;
    }
};