// Given an array nums and an integer k. R﻿eturn true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.


// Example 1

// Input : nums = [1, 2, 3, 4, 5] , k = 8

// Output : Yes

// Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

// Example 2

// Input : nums = [4, 3, 9, 2] , k = 10

// Output : No

// Explanation : No subsequence can sum up to 10.
class Solution{
    public:
     bool recurse(vector<int>&nums,int k,int sum,int idx){
        if(sum==k) return true;
        if(sum>k) return false;
        if(idx==nums.size()){
            if(sum==k) return true;
            return false;
        }
        int l=recurse(nums,k,sum+nums[idx],idx+1);
        int r=recurse(nums,k,sum,idx+1);
        return l || r;
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
          return recurse(nums,k,0,0);
    }
};