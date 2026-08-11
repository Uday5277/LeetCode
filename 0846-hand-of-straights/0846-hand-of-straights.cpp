class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int,int>mp;
        for(int i = 0 ; i<hand.size() ; i++){
            mp[hand[i]]++;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &it:mp){
            pq.push(it.first);
        }
        while(!pq.empty()){
            int ele = pq.top();
            if(mp[ele] == 0){
                pq.pop();
                continue;
            }

            for(int i = ele ; i<ele+groupSize ; i++){
                if(mp.find(i) == mp.end() || mp[i] == 0) return false;
                mp[i]--;
                if(mp[i] == 0){
                    mp.erase(i);
                }
            }
        }
        return true;
    }
};