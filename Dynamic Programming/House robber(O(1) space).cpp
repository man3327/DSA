class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int prev=nums[0];
        int prev2=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int curr=max(prev2,prev+nums[i]);
            prev=prev2;
            prev2=curr;
        }return prev2;
    }
};