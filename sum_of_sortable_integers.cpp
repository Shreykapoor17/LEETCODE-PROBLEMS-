#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canSortWithK(vector<int>& nums, vector<int>& sortedNums, int k) {
        int n = nums.size();

        for (int start = 0; start < n; start += k) {
            int drops = 0;
            int rotationStart = 0;

            for (int i = 0; i < k - 1; i++) {
                if (nums[start + i] > nums[start + i + 1]) {
                    drops++;
                    rotationStart = i + 1;
                }
            }

            if (drops > 1) {
                return false;
            }

            for (int j = 0; j < k; j++) {
                int index = start + (rotationStart + j) % k;

                if (nums[index] != sortedNums[start + j]) {
                    return false;
                }
            }
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int answer = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k == 0 && canSortWithK(nums, sortedNums, k)) {
                answer += k;
            }
        }

        return answer;
    }
};

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int result = obj.sortableIntegers(nums);

    cout << "Sum of sortable integers: " << result << endl;

    return 0;
}