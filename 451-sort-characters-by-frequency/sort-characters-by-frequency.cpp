class Solution {
public:
    string frequencySort(string s) {

        // 1. Count frequency
        unordered_map<char, int> freq;

        for(char c : s) {
            freq[c]++;
        }

        // 2. Store character and frequency
        vector<pair<char, int>> arr;

        for(auto x : freq) {
            arr.push_back(x);
        }

        // 3. Sort by frequency (highest first)
        sort(arr.begin(), arr.end(),
            [](auto &a, auto &b) {
                return a.second > b.second;
            });

        // 4. Build answer
        string ans;

        for(auto x : arr) {
            char ch = x.first;
            int count = x.second;

            while(count--) {
                ans += ch;
            }
        }

        return ans;
    }
};