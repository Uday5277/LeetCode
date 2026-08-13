class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>freqMap;
        for(int i = 0 ; i<nums.size() ; i++){
            freqMap[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto &it:freqMap){
            if(pq.size()<k){
                pq.push({it.second,it.first});
            }else{
                if(it.second>pq.top().first){
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
        }
        vector<int>result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};