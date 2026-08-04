class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        // Count frequencies
        for(int x : nums)
        {
            mp[x]++;
            
        }

        // Store (frequency, number)
        vector<pair<int,int>> freq;

        for(auto it : mp)
        {
            freq.push_back({it.second, it.first});
        }

        // Sort by frequency (highest first)
        sort(freq.begin(), freq.end(), greater<pair<int,int>>());

        // Take first k numbers
        vector<int> ans;

        for(int i = 0; i < k; i++)
        {
            ans.push_back(freq[i].second);
        }

        return ans;
    }
};