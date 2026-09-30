#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValidPath(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Total number of cells in any path
    int len = m + n - 1;

    // A valid parentheses string must have even length
    if (len % 2 != 0)
        return false;

    // dp[i][j][balance]
    vector<vector<vector<bool>>> dp(
        m, vector<vector<bool>>(n, vector<bool>(len + 1, false))
    );

    // Starting cell
    int startBalance = (grid[0][0] == '(') ? 1 : -1;

    if (startBalance < 0)
        return false;

    dp[0][0][startBalance] = true;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0)
                continue;

            for (int balance = 0; balance <= len; balance++) {

                // Current character changes the balance
                int change = (grid[i][j] == '(') ? 1 : -1;

                int previousBalance = balance - change;

                if (previousBalance < 0 || previousBalance > len)
                    continue;

                // From the cell above
                if (i > 0 && dp[i - 1][j][previousBalance])
                    dp[i][j][balance] = true;

                // From the cell on the left
                if (j > 0 && dp[i][j - 1][previousBalance])
                    dp[i][j][balance] = true;
            }
        }
    }

    // Valid parentheses string must finish with balance 0
    return dp[m - 1][n - 1][0];
}

int main() {

    int m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    cout << "Enter the grid:\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if (isValidPath(grid))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}