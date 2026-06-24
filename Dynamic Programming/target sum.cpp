// //Similar to subset sum with given difference
// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000
//OBSERVATION
//take two subsets s1 and s2
//s1+s2 == totalsum
//s1-s2 == target
//2s1=totalsum + target
//s1=(total+target)/2
//if its odd return 0 becoz we cant partition in anyway to make same differences of two subset if their sum is odd
class Solution {
public:
int recurse(int n,int target,vector<int>& nums){
    if(n<0){
        if(target==0) return 1;
        return 0;
    }int plus=0;
    if(target-nums[n]>=0)plus=recurse(n-1,target-nums[n],nums);
    int minus=recurse(n-1,target,nums);
    return plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto &p:nums) sum+=p;
        int newtarget=(sum+target);
        if(newtarget%2==0) newtarget/=2;
        else return 0;
        return recurse(nums.size()-1,newtarget,nums);
    }
}; //the rest solution and optimisation is same as subset sum question
