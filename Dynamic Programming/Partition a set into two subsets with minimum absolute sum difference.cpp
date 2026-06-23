// Given an array arr of n integers, partition the array into two subsets such that the absolute difference between their sums is minimized.


// Example 1

// Input: arr = [1, 7, 14, 5]

// Output: 1

// Explanation: The array can be partitioned as [1, 7, 5] and [14], with an absolute difference of 1.

// Example 2

// Input: arr = [3, 1, 6, 2, 2]

// Output: 0

// Explanation: The array can be partitioned as [3, 2, 2] and [6, 1], with an absolute difference of 0.
//ALTERNATE QUESTION ON LEETCODE
//LAST STONE WEIGHT II
// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the smallest possible weight of the left stone. If there are no stones left, return 0.

 

// Example 1:

// Input: stones = [2,7,4,1,8,1]
// Output: 1
// Explanation:
// We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
// we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
// we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
// we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
// Example 2:

// Input: stones = [31,26,33,21,40]
// Output: 5
 

// Constraints:

// 1 <= stones.length <= 30
// 1 <= stones[i] <= 100
class Solution {
public:
int sum=0;
vector<vector<int>>dp;
int recurse(int n,int sum,int curr,vector<int>& stones){
    if(n<0) return abs(curr-sum);
    if(dp[n][curr]!=-1) return dp[n][curr];
    int pick=recurse(n-1,sum-stones[n],curr+stones[n],stones);
    int np=recurse(n-1,sum,curr,stones);
    return dp[n][curr]=min(pick,np);
}
    int lastStoneWeightII(vector<int>& stones) {
        for(auto &p:stones) sum+=p;
        dp.resize(stones.size(),vector<int>(sum+1,-1));
        return recurse(stones.size()-1,sum,0,stones);
    }
};