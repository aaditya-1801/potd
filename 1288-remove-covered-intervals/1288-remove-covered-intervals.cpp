class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        int n = intervals.size();
        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            if(vec1[0] == vec2[0])
                return vec1[1] > vec2[1];
            
            return vec1[0] < vec2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        res.push_back(intervals[0]);

        for(int i=0; i<n; i++){
            if(res.back()[0] <= intervals[i][0] && res.back()[1] >= intervals[i][1])
                continue;

            res.push_back(intervals[i]);
        }

        return res.size();
    }
};