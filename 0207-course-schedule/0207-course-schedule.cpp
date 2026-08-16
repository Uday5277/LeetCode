class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjList(numCourses);
        for(int i = 0 ; i<prerequisites.size() ; i++){
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>inDegree(numCourses,0);
        for(int i = 0 ; i<numCourses ; i++){
            for(int& it:adjList[i]){
                inDegree[it]++;
            }
        }
        queue<int>q;
        int cnt = 0;
        for(int i = 0 ; i < numCourses ; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(int &i:adjList[node]){
                inDegree[i]--;
                if(inDegree[i] == 0) q.push(i);
            }
        }
        return cnt == numCourses;
    }
};