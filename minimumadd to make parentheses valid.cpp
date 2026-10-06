#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int answer = 0;

        for (char c : s) {
            if (c == '(') {
                open++;
            }
            else {
                if (open > 0) {
                    open--;
                }
                else {
                    answer++;
                }
            }
        }

        answer += open;

        return answer;
    }
};

int main() {
    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    Solution obj;

    int result = obj.minAddToMakeValid(s);

    cout << "Minimum additions required: " << result << endl;

    return 0;
}