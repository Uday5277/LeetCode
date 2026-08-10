class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>hashmap(26,0);
        for(int i = 0 ; i < tasks.size() ; i++){
            hashmap[tasks[i]-'A']++;
        }
        for(int i = 0 ; i<26 ; i++){
            if(hashmap[i]>0) pq.push(hashmap[i]);
        }

        queue<pair<int,int>>q;
        int ans = 0;
        while(!pq.empty() || !q.empty()){
            ans++;
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                freq--;
                if(freq>0){
                    q.push({freq,ans+n});
                }
            }
            while(!q.empty() && q.front().second<=ans){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return ans;
    }

};