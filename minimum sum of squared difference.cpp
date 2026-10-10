class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(nums1.size());
        long long operations = (long long)k1 + k2;

        int maxDiff = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        if (accumulate(diff.begin(), diff.end(), 0LL) <= operations) {
            return 0;
        }

        vector<long long> freq(maxDiff + 1, 0);

        for (int d : diff) {
            freq[d]++;
        }

        for (int d = maxDiff; d > 0 && operations > 0; d--) {
            long long count = min(freq[d], operations);
            freq[d] -= count;
            freq[d - 1] += count;
            operations -= count;
        }

        long long result = 0;

        for (int d = 1; d <= maxDiff; d++) {
            result += freq[d] * d * d;
        }

        return result;
    }
};