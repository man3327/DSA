// Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.


// Example 1

// Input : nums = [4, 9, 2, 5, 1] , k = 10

// Output : 2

// Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].

// Example 2

// Input : nums = [4, 2, 10, 5, 1, 3] , k = 5

// Output : 3

// Explanation : The possible subsets with sum k are [4, 1] , [2, 3] , [5].
class Solution{
    public:    	
    int recurse(vector<int>&nums,int k,int sum,int idx){
        if(sum==k) return 1;
        if(sum>k) return 0;
        if(idx==nums.size()){
            if(sum==k) return 1;
            return 0;
        }
        int l=recurse(nums,k,sum+nums[idx],idx+1);
        int r=recurse(nums,k,sum,idx+1);
        return l+r;
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	return recurse(nums,k,0,0);
    }
};