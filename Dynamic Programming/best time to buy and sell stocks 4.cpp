// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
// Example 2:

// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

// Constraints:

// 1 <= k <= 100
// 1 <= prices.length <= 1000
// 0 <= prices[i] <= 1000
//EXACTLY SAME AS 3RD PART ,JUST THE CAPACITY IS K HERE ,NOT 2
class Solution {
public:
#define ll long long
vector<vector<vector<ll>>> dp;
int recurse(int i,vector<int>& prices,bool buy,int cap){
    if(i==prices.size() || cap==0){
        return 0;
    }if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
    ll profit=0,notprofit=0;
    if(buy){
        profit = -prices[i] + recurse(i+1,prices,false,cap);
        notprofit = recurse(i+1,prices,true,cap);
    }else {
        profit = prices[i] + recurse(i+1,prices,true,cap-1);
        notprofit = recurse(i+1,prices,false,cap);
    }
    return dp[i][buy][cap]=max(profit,notprofit);
}
    int maxProfit(int k, vector<int>& prices) {
        dp.resize(prices.size(),vector<vector<ll>>(2,vector<ll>(k+1,-1)));
        return recurse(0,prices,true,k);
    }
};