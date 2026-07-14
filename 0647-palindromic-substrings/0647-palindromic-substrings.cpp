class Solution {
public:
    int expand(string &s, int l, int r) {
        int cnt = 0;

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            cnt++;
            l--;
            r++;
        }

        return cnt;
    }

    int countSubstrings(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            // Odd length palindrome
            ans += expand(s, i, i);

            // Even length palindrome
            ans += expand(s, i, i + 1);
        }

        return ans;
    }
};

// class Solution {
// public:
//     bool isPalindrome(string &s, int l, int r) {
//         while (l < r) {
//             if (s[l++] != s[r--])
//                 return false;
//         }
//         return true;
//     }

//     int countSubstrings(string s) {
//         int n = s.size();
//         int cnt = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 if (isPalindrome(s, i, j))
//                     cnt++;
//             }
//         }

//         return cnt;
//     }
// };