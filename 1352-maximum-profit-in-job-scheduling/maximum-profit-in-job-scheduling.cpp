class Solution {
public:
    vector<vector<int>> jobs;
    vector<int> dp;

    int solve(int i) {
        if (i == jobs.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // 1. Skip current job
        int skip = solve(i + 1);

        // 2. Take current job
        // Find first job whose start time >= current end time
        int next = lower_bound(
            jobs.begin() + i + 1,
            jobs.end(),
            vector<int>{jobs[i][1], 0, 0}
        ) - jobs.begin();

        int take = jobs[i][2] + solve(next);

        return dp[i] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        // {start, end, profit}
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Sort by START TIME
        sort(jobs.begin(), jobs.end());

        dp.assign(n, -1);

        return solve(0);
    }
};
