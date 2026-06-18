// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
class Solution {
public:
vector<vector<int>> vec;
vector<int> res;
void recurse(int n,vector<int> nums,int start){
vec.push_back(res);
for(int i=start;i<nums.size();i++){
    if(start<i && nums[i]==nums[i-1]) continue;
    res.push_back(nums[i]);
    recurse(n,nums,i+1);
    res.pop_back();
}
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        recurse(nums.size(),nums,0);
        return vec;
    }
};