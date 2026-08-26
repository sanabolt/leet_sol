class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert all integers to strings
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        
        // Sort using the custom comparator
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        // Edge case: if the highest value is "0", the entire number is 0
        if (strs[0] == "0") {
            return "0";
        }
        
        // Concatenate the sorted strings
        string result;
        for (const string& s : strs) {
            result += s;
        }
        
        return result;
    }
};