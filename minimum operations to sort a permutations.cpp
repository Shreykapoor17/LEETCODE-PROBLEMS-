#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                sorted = false;
                break;
            }
        }

        if (sorted) return 0;

        int p = find(nums.begin(), nums.end(), 0) - nums.begin();
        int ans = INT_MAX;

        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (nums[(p + j) % n] != j) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(p, n - p + 2);
        }

        vector<int> rev(nums.rbegin(), nums.rend());
        int q = n - 1 - p;

        ok = true;
        for (int j = 0; j < n; j++) {
            if (rev[(q + j) % n] != j) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, min(q + 1, n - q + 1));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter permutation elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << "Minimum operations: "
         << obj.minOperations(nums) << endl;

    return 0;
}