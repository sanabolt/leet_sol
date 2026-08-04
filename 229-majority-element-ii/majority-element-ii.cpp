class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int,int> mp;

        // Count frequency
        for(int x : nums)
        {
            mp[x]++;
        }

        vector<int> ans;

        // Check whose frequency is greater than n/3
        for(auto it : mp)
        {
            if(it.second > nums.size()/3)
            {
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};