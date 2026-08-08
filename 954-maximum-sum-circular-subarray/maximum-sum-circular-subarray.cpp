class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;

        int currentMax = 0;
        int maxSum = nums[0];

        int currentMin = 0;
        int minSum = nums[0];

        for(int x : nums) {

            totalSum += x;

            // Kadane for maximum
            currentMax = max(x, currentMax + x);
            maxSum = max(maxSum, currentMax);

            // Kadane for minimum
            currentMin = min(x, currentMin + x);
            minSum = min(minSum, currentMin);
        }

        // All numbers are negative
        if(maxSum < 0)
            return maxSum;

        int circularSum = totalSum - minSum;

        return max(maxSum, circularSum);
    }
};