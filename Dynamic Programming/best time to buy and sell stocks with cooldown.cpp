// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
// Example 2:

// Input: prices = [1]
// Output: 0
 

// Constraints:

// 1 <= prices.length <= 5000
// 0 <= prices[i] <= 1000
class Solution {
public:
vector<vector<int>> dp;
int recurse(int idx,bool buy,vector<int>& p){
    if(idx>=p.size()) return 0;
    if(dp[idx][buy]!=-1) return dp[idx][buy];
    int profit=0;int profitnot=0;
    if(buy){
        profit = -p[idx] + recurse(idx+1,false,p);
        profitnot = recurse(idx+1,true,p);
    }else{
        profit=p[idx]+recurse(idx+2,true,p);//if we have sell the transactiion then we cant buy on next day so we skip that index,the rest is same as BTTBASS 2
        profitnot=recurse(idx+1,false,p);
    }return dp[idx][buy]=max(profit,profitnot);
}
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+1,vector<int>(2,-1));
        return recurse(0,true,prices);
    }
};