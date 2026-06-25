// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The final answer is guaranteed to fit into a signed 32-bit integer.

 

// Example 1:

// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
// Example 3:

// Input: amount = 10, coins = [10]
// Output: 1
 

// Constraints:

// 1 <= coins.length <= 300
// 1 <= coins[i] <= 5000
// All the values of coins are unique.
// 0 <= amount <= 5000
class Solution {
public:
#define ull unsigned long long
vector<vector<ull>> dp;
int recurse(int n,int amount,vector<int>& coins){
    if(n==0){
        if(amount%coins[n]==0) return 1;
        else return 0;
    }
    int pick=0;
    if(dp[n][amount]!=-1) return dp[n][amount];
    if(amount-coins[n]>=0) pick=recurse(n,amount-coins[n],coins);
    int np=recurse(n-1,amount,coins);
    return dp[n][amount]=pick+np;
}
    int change(int amount, vector<int>& coins) {
        //dp.resize(coins.size(),vector<int>(amount+1,-1));//for recursion
        //return recurse(coins.size()-1,amount,coins);//for recursion
        //Tabulation--------------
        /*dp.resize(coins.size(),vector<ull>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=1;
        }
        for(int i=1;i<coins.size();i++){
            for(int t=0;t<=amount;t++){
                dp[i][t]=dp[i-1][t];
                if(t-coins[i]>=0) dp[i][t]=(ull)(dp[i][t]+dp[i][t-coins[i]]);
            }
        }return dp[coins.size()-1][amount];*/
        vector<ull> prev(amount+1,0),curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i]=1;
        }
        for(int i=1;i<coins.size();i++){
            for(int t=0;t<=amount;t++){
                curr[t]=prev[t];
                if(t-coins[i]>=0) curr[t]=(ull)(curr[t]+curr[t-coins[i]]);
            }prev=curr;
        }return prev[amount];
    }
};