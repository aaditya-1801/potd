class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // vector<vector<int>> res;

        int n = intervals.size();
        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            if(vec1[0] == vec2[0])
                return vec1[1] > vec2[1];
            
            return vec1[0] < vec2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        // res.push_back(intervals[0]);
        int cnt = 1;
        int left = intervals[0][0];
        int right = intervals[0][1];

        for(int i=1; i<n; i++){
            // res.back()[0] <= intervals[i][0] ...this is redundant as we sorted intervals
            // if(res.back()[0] <= intervals[i][0] && res.back()[1] >= intervals[i][1])
            if(left <= intervals[i][0] && right >= intervals[i][1])
                continue;

            // res.push_back(intervals[i]);
            cnt += 1;
            left = intervals[i][0];
            right = intervals[i][1];
        }

        // return res.size(); 
        return cnt;
    }
};