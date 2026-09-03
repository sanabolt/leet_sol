class Solution {
public:
    int solve(vector<int>& nums, int target, int index, int sum,
              vector<vector<int>>& dp) {

        // All numbers used
        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }

        // Already calculated
        if (dp[index][sum + 1000] != -1) {
            return dp[index][sum + 1000];
        }

        // Choose +
        int add = solve(nums, target, index + 1, sum + nums[index], dp);

        // Choose -
        int subtract = solve(nums, target, index + 1, sum - nums[index], dp);

        return dp[index][sum + 1000] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));

        return solve(nums, target, 0, 0, dp);
    }
};