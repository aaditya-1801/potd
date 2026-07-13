class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();

        for(int i=0; i<n; i++) st.insert(nums[i]);

        vector<int> res;
        for(int i=1;i<=n; i++){
            if(st.find(i) == st.end()) res.push_back(i);
        }

        return res;
    }
};