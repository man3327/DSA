// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 105
class Solution {
public:
vector<vector<vector<int>>> dp;
int recurse(int i,vector<int>& prices,bool buy,int cap){
    if(i==prices.size() || cap==0){
        return 0;
    }if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
    int profit=0,notprofit=0;
    if(buy){
        profit = -prices[i] + recurse(i+1,prices,false,cap);
        notprofit = recurse(i+1,prices,true,cap);
    }else {
        profit = prices[i] + recurse(i+1,prices,true,cap-1);//we have bought and sell the stock ,so 1 transaction is completed ,so capacity--
        notprofit = recurse(i+1,prices,false,cap);
    }
    return dp[i][buy][cap]=max(profit,notprofit);
}
    int maxProfit(vector<int>& prices) {
        //dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        dp.resize(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));//capacity is 2
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit=0,notprofit=0;
                    if(buy){
                    profit = -prices[i] + dp[i+1][false][cap];
                    notprofit = dp[i+1][true][cap];
                    }else {
                    profit = prices[i] + dp[i+1][true][cap-1];
                    notprofit = dp[i+1][false][cap];
                    }
                    dp[i][buy][cap]=max(profit,notprofit);
                }
            }
        }return dp[0][1][2];
        //return recurse(0,prices,true,2);
    }
};
//space optimisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> after(2,vector<int>(3,0));
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit=0,notprofit=0;
                    if(buy){
                    profit = -prices[i] + after[false][cap];
                    notprofit = after[true][cap];
                    }else {
                    profit = prices[i] + after[true][cap-1];
                    notprofit = after[false][cap];
                    }
                    curr[buy][cap]=max(profit,notprofit);
                }
            }after=curr;
        }return after[1][2];
    }
};