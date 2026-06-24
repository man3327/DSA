// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
//Recursion+memoization
 class Solution {
public:
vector<vector<int>> dp;
int recurse(int n,vector<int>&coins,int amount){
    if(n==0){
        if(amount%coins[n]==0) return amount/coins[n];
        return 1e6;
    }if(dp[n][amount]!=-1) return dp[n][amount];
    int pick=INT_MAX;
    if(amount-coins[n]>=0){
        pick=1+recurse(n,coins,amount-coins[n]);
    }int np=recurse(n-1,coins,amount);
    return dp[n][amount]=min(pick,np);
}
    int coinChange(vector<int>& coins, int amount) {
        // dp.resize(coins.size(),vector<int>(amount+1,0));
        //if(recurse(coins.size()-1,coins,amount)==1e6) return -1;
        dp.resize(coins.size(),vector<int>(amount+1,0));
        //tabulation
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e6;
        }
        if(recurse(coins.size()-1,coins,amount)==1e6) return -1;
        for(int i=1;i<coins.size();i++){
            for(int T=0;T<=amount;T++){
                int pick=INT_MAX;
                if(coins[i]<=T){
                pick=1+dp[i][T-coins[i]];
                }int np=dp[i-1][T];
                
             dp[i][T]=min(pick,np);
            }
        }
        if(dp[coins.size()-1][amount]==1e6) return -1 ;
        return dp[coins.size()-1][amount];
        //return recurse(coins.size()-1,coins,amount);
    }
};
//space optimisation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { 
        vector<int> prev(amount+1,0),curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i]=i/coins[0];
            else prev[i]=1e6;
        }
        for(int i=1;i<coins.size();i++){
            for(int T=0;T<=amount;T++){
                int pick=INT_MAX;
                if(coins[i]<=T){
                pick=1+curr[T-coins[i]];
                }int np=prev[T];
             curr[T]=min(pick,np);
            }prev=curr;
        }
        if(prev[amount]==1e6) return -1 ;
        return prev[amount];
    }
};