// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

// Find and return the maximum profit you can achieve.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

// Constraints:

// 1 <= prices.length <= 3 * 104
// 0 <= prices[i] <= 104
class Solution {
public:
vector<vector<int>> dp;
int recurse(int idx,bool buy,vector<int>& p){
    if(idx==p.size()) return 0;
    if(dp[idx][buy]!=-1) return dp[idx][buy];
    int profit=0;int profitnot=0;
    if(buy){
        profit = -p[idx] + recurse(idx+1,false,p);
        profitnot = recurse(idx+1,true,p);
    }else{
        profit=p[idx]+recurse(idx+1,true,p);
        profitnot=recurse(idx+1,false,p);
    }return dp[idx][buy]=max(profit,profitnot);
}
    int maxProfit(vector<int>& prices) {
    //dp.resize(prices.size()+1,vector<int>(2,-1));
    dp.resize(prices.size()+1,vector<int>(2,0));
    for(int idx=prices.size()-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            int profitnot=0;
            if(buy){
                profit = -prices[idx] + dp[idx+1][0];
                profitnot = dp[idx+1][1];
            }else{
                profit=prices[idx]+dp[idx+1][1];
                profitnot=dp[idx+1][0];
            }dp[idx][buy]=max(profit,profitnot);
        }
    }
    return dp[0][1];
    //return recurse(0,true,prices);
     }
};
//space optimisation
//1. by making two rows curr and prev
//2nd by variables
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int mini=prices[0];
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            if(prices[i]>mini){
                ans+=(prices[i]-mini);
                mini=prices[i];
            }
        }return ans;
    }
};