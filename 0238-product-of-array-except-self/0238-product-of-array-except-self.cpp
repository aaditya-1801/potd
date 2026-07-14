class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int prefix = 1;

        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;

        // int n = nums.size();
        // vector<int> prefix(n);
        // vector<int> suffix(n);
        // vector<int> ans(n);

        // prefix[0] = 1;
        // for(int i = 1; i < n; i++){
        //     prefix[i] = prefix[i-1] * nums[i-1];
        // }

        // suffix[n-1] = 1;
        // for(int i = n-2; i >= 0; i--){
        //     suffix[i] = suffix[i+1] * nums[i+1];
        // }

        // for(int i = 0; i < n; i++){
        //     ans[i] = prefix[i] * suffix[i];
        // }

        // return ans;
    }
};