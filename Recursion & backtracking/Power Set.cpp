//Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.
class Solution {
public:
vector<int> subset;
void search(vector<vector<int>>& s,vector<int> nums,int k,int n){
    if(k==n){
        s.push_back(subset);
        return;
    }
    search(s,nums,k+1,n);
    subset.push_back(nums[k]);
    search(s,nums,k+1,n);
    subset.pop_back();
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> s;
        search(s,nums,0,nums.size());
        return s;
        
    }
};