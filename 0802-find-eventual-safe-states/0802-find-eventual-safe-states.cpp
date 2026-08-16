class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adjRev(n);
        for(int i = 0 ; i<n ; i++){
            for(int it:graph[i]){
                adjRev[it].push_back(i);
            }
        }

        vector<int>inDegree(n,0);
        for(int i = 0 ; i<n ; i++){
            for(int it: adjRev[i]){
                inDegree[it]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i = 0 ; i<n ; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int i:adjRev[node]){
                inDegree[i]--;
                if(inDegree[i] == 0) q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};