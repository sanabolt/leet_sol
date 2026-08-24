class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Cannot reach this position
            if (i > maxReach)
                return false;

            // Update farthest position we can reach
            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};