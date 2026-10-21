#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(), t.end());

        if (s == t) return 0;

        int n = s.size();

        if (n == 2) return -1;

        if (s[0] == t[0] || s[n - 1] == t[n - 1])
            return 1;

        if (s[0] == t[n - 1] && s[n - 1] == t[0] &&
            count(s.begin(), s.end(), s[0]) == 1 &&
            count(s.begin(), s.end(), s[n - 1]) == 1)
            return 3;

        return 2;
    }
};

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    Solution obj;
    cout << "Minimum operations: " << obj.minOperations(s) << endl;

    return 0;
}