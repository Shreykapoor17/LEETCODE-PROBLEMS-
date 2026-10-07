#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;

                if (balance < 0) {
                    return false;
                }
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;

        unordered_set<string> current;
        current.insert(s);

        while (true) {

            for (string str : current) {
                if (isValid(str)) {
                    result.push_back(str);
                }
            }

            if (!result.empty()) {
                break;
            }

            unordered_set<string> next;

            for (string str : current) {

                for (int i = 0; i < str.length(); i++) {

                    if (str[i] != '(' && str[i] != ')') {
                        continue;
                    }

                    string newStr = str.substr(0, i) + str.substr(i + 1);

                    next.insert(newStr);
                }
            }

            current = next;
        }

        return result;
    }
};

int main() {

    string s;

    cout << "Enter the string: ";
    cin >> s;

    Solution obj;

    vector<string> result = obj.removeInvalidParentheses(s);

    cout << "Valid strings with minimum removals:" << endl;

    for (string str : result) {
        cout << "\"" << str << "\"" << endl;
    }

    return 0;
}