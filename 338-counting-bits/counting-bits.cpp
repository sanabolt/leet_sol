
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);

        for (int i = 0; i <= n; i++) {
            int x = i;
            while (x > 0) {
                ans[i] += x % 2;
                x /= 2;
            }
        }

        return ans;
    }
};

