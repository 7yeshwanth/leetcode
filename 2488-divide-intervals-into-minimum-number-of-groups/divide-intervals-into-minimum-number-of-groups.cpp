class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> et;
        for(auto it: intervals){
            if(!et.empty() && et.top() < it[0]){
                et.pop();
            }
            et.push(it[1]);
        }
        return et.size();
    }
};