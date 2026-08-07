class Solution {
public:
    int maxProduct(vector<int>& nums) { 
        int maxProduct=nums[0];
        int minProduct=nums[0];
        int answer=nums[0];
        for(int i=1;i<nums.size();i++){
            int curr=nums[i];
            int tempMax=max({curr,curr*maxProduct,curr*minProduct});
            int tempMin=min({curr,curr*maxProduct,curr*minProduct});

            maxProduct=tempMax;
            minProduct=tempMin;

            answer=max(answer,maxProduct);

        }return answer;

       
    }
};