// Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
class Solution {
public:
vector<vector<int>>dp;
int recurse(int idx,vector<int>& nums,int prev){
    if(idx==nums.size()) return 0;
    if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
    int pick=0;
    if(prev==-1 || nums[prev]<nums[idx])pick=1+recurse(idx+1,nums,idx);
    int np=recurse(idx+1,nums,prev);
    return dp[idx][prev+1] = max(pick,np);
}
    int lengthOfLIS(vector<int>& nums) {
        // dp.resize(nums.size(),vector<int>(nums.size()+1,-1));
        dp.resize(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int idx=nums.size()-1;idx>=0;idx--){
            for(int prev=idx-1;prev>=-1;prev--){
                int pick=0;
                if(prev==-1 || nums[prev]<nums[idx]) pick=1+dp[idx+1][idx+1];
                int np=dp[idx+1][prev+1];
                 dp[idx][prev+1] = max(pick,np);
            }
        }return dp[0][0];
        //return recurse(0,nums,-1);
    }
};
//space optimisation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>next(nums.size()+1,0),curr(nums.size()+1,0);
        for(int idx=nums.size()-1;idx>=0;idx--){
            for(int prev=idx-1;prev>=-1;prev--){
                int pick=0;
                if(prev==-1 || nums[prev]<nums[idx]) pick=1+next[idx+1];
                int np=next[prev+1];
                curr[prev+1] = max(pick,np);
            }next=curr;
        }return curr[0];
    }
};
//more optimised
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        for(int idx=0;idx<nums.size();idx++){
            for(int prev=0;prev<idx;prev++){
                if(nums[prev]<nums[idx]) dp[idx]=max(dp[idx],dp[prev]+1);
            }
        }
        int maxi=INT_MIN;
        for(auto &p:dp) maxi=max(maxi,p);
        return maxi;
    }
};