// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        int cnt=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k) cnt++;//current subarray with sum k
            if(mpp.find(sum-k)!=mpp.end()){
                cnt+=mpp[sum-k];//previous subarrays with sum sum-k
            }mpp[sum]++;//store the current subarray with sum k,its count
        }return cnt;
    }
};