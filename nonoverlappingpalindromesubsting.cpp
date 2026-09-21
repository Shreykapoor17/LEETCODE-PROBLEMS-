class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j]) {

                    
                    if (j - i <= 1) {
                        pal[i][j] = true;
                    }

                    // Length >= 3
                    else {
                        pal[i][j] = pal[i + 1][j - 1];
                    }
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // using the first i characters
        vector<int> dp(n + 1, 0);

        // Step 2: Find maximum number of non-overlapping palindromes
        for (int i = 1; i <= n; i++) {

            // Don't use a palindrome ending at i-1
            dp[i] = dp[i - 1];

            // Try every possible starting position
            for (int j = 0; j < i; j++) {

                // Length of substring s[j...i-1]
                int len = i - j;

                // Check minimum length and palindrome condition
                if (len >= k && pal[j][i - 1]) {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};