class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();

        // {start, end, profit}
        vector<array<int, 3>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Sort jobs by starting time
        sort(jobs.begin(), jobs.end());

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Find first job whose start >= current job's end
            int next = lower_bound(
                jobs.begin() + i + 1,
                jobs.end(),
                array<int, 3>{jobs[i][1], 0, 0}
            ) - jobs.begin();

            // Take current job
            int take = jobs[i][2] + dp[next];

            // Skip current job
            int skip = dp[i + 1];

            dp[i] = max(take, skip);
        }

        return dp[0];
    }
};