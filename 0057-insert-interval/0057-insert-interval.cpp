class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans = intervals;
        ans.push_back(newInterval);
        sort(ans.begin(),ans.end());
        vector<vector<int>>res;
        for(int i = 0 ; i<ans.size() ; i++){
            if(res.empty() || res.back()[1]<ans[i][0]){
                res.push_back(ans[i]);
            }else{
                res.back()[1] = max(res.back()[1],ans[i][1]);
            }
        }
        return res;
    }
};