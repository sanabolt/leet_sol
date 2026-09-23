class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;

        // XOR all numbers
        for (int n : nums) {
            x ^= n;
        }

        // Find any bit where the two unique numbers differ
        int mask = 1;

        while ((x & mask) == 0) {
            mask <<= 1;
        }

        int a = 0;
        int b = 0;

        // Divide into two groups
        for (int n : nums) {
            if (n & mask)
                a ^= n;
            else
                b ^= n;
        }

        return {a, b};
    }
};