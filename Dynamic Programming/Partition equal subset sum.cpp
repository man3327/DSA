// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100
class Solution {
public:
vector<vector<int>> dp;
bool recurse(int i,int sum,int target,vector<int>&nums){
    if(sum==target/2) return true;
    if(i==nums.size()){
        if(sum==target/2) return true;
        else return false;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool pick=recurse(i+1,sum+nums[i],target,nums);
    bool np=recurse(i+1,sum,target,nums);
    return dp[i][sum]=pick || np;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &p:nums) sum+=p;
        dp.resize(nums.size(),vector<int>(sum+1,-1));
        if(sum%2) return false;
        return recurse(0,0,sum,nums);
    }
};