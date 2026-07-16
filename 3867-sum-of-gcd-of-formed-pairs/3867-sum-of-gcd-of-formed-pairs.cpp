class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n, 0);

        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);

            prefixGcd[i] = __gcd(mx, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int l = 0;
        int r = n-1;
        long long sum = 0;
        while(l < r){
            int pairGcd = __gcd(prefixGcd[l++], prefixGcd[r--]);
            sum += pairGcd;
        }

        return sum;
    }
};