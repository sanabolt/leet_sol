class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        // Sort by units per box in descending order
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] > b[1];
             });

        int totalUnits = 0;

        for (auto box : boxTypes) {
            
            int boxes = min(truckSize, box[0]);

            totalUnits += boxes * box[1];

            truckSize -= boxes;

            if (truckSize == 0)
                break;
        }

        return totalUnits;
    }
};