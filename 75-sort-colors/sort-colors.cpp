
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        // Count occurrences
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                count0++;
            else if (nums[i] == 1)
                count1++;
            else
                count2++;
        }

        // Fill zeros
        int i = 0;

        while (count0--) {
            nums[i++] = 0;
        }

        // Fill ones
        while (count1--) {
            nums[i++] = 1;
        }

        // Fill twos
        while (count2--) {
            nums[i++] = 2;
        }
    }
};
