class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> digits;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        vector<long long> prefSum(m + 1, 0);
        vector<long long> prefNum(m + 1, 0);
        vector<long long> pow10(m + 1, 1);

        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digits[i];
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> firstNonZero(n, -1);
        vector<int> lastNonZero(n, -1);

        int idx = 0;
        for (int i = 0; i < n; i++) {
            while (idx < m && pos[idx] < i)
                idx++;
            if (idx < m)
                firstNonZero[i] = idx;
        }

        idx = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (idx >= 0 && pos[idx] > i)
                idx--;
            if (idx >= 0)
                lastNonZero[i] = idx;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int L = firstNonZero[q[0]];
            int R = lastNonZero[q[1]];

            if (L == -1 || R == -1 || L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R + 1] - prefSum[L];

            long long x = (prefNum[R + 1] - prefNum[L] * pow10[R - L + 1] % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};