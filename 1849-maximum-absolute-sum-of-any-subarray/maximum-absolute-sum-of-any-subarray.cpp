class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int currentMax = 0;
        int maxSum = 0;

        int currentMin = 0;
        int minSum = 1;

        for(int x : nums) {

            // Maximum subarray sum
            currentMax = max(x, currentMax + x);
            maxSum = max(maxSum, currentMax);

            // Minimum subarray sum
            currentMin = min(x, currentMin + x);
            minSum = min(minSum, currentMin);
        }

        return max(maxSum, abs(minSum));
    }
};