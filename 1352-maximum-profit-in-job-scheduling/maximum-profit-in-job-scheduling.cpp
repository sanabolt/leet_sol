class Solution {
public:
    vector<vector<int>> jobs;
    vector<int> dp;

    int solve(int i) {
        if (i == jobs.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Skip current job
        int skip = solve(i + 1);

        // Binary Search
        int low = i + 1;
        int high = jobs.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (jobs[mid][0] >= jobs[i][1])
                high = mid;
            else
                low = mid + 1;
        }

        int next = low;

        // Take current job
        int take = jobs[i][2] + solve(next);

        return dp[i] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        for (int i = 0; i < n; i++) {
            jobs.push_back({
                startTime[i],
                endTime[i],
                profit[i]
            });
        }

        // Sort by start time
        sort(jobs.begin(), jobs.end());

        dp.assign(n, -1);

        return solve(0);
    }
};
