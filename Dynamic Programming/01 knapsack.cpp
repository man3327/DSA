// Given two arrays, val[] and wt[], where each element represents the value and weight of an item respectively, and an integer W representing the maximum capacity of the knapsack (the total weight it can hold).

// The task is to put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity W.

// Note: You can either include an item completely or exclude it entirely — fractional selection of items is not allowed. Each item is available only once.

// Examples :

// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
// Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).
// Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
// Output: 80
// Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
// Constraints:
// 1 ≤ val.size() = wt.size() ≤ 103
// 1 ≤ W ≤ 103
// 1 ≤ val[i] ≤ 103
// 1 ≤ wt[i] ≤ 103
//Recursion+Memoization
class Solution {
  public:
  vector<vector<int>> dp;
  int recurse(int n,int W,int weight,vector<int>&wt,vector<int>&val){
      if(n<0){
         return 0;
      }if(dp[n][weight]!=-1) return dp[n][weight];
      int pick=0;
      if(wt[n]+weight<=W) pick=val[n]+recurse(n-1,W,weight+wt[n],wt,val);
      int np=recurse(n-1,W,weight,wt,val);
      return dp[n][weight]=max(pick,np);
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        dp.resize(val.size(),vector<int>(W+1,-1));
        return recurse(val.size()-1,W,0,wt,val);
        
    }
};
//tabulation
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for(int weight=wt[0];weight<=W;weight++) dp[0][weight]=val[0];
        for(int i=1;i<n;i++){
            for(int weight=0;weight<=W;weight++){
                int pick=0;
                if(wt[i]<=weight) pick=val[i]+dp[i-1][weight-wt[i]];
                int np=dp[i-1][weight];
                dp[i][weight]=max(pick,np);
            }
        }return dp[n-1][W];
    }
};
//Space optimisation
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<int> prev(W+1,0);
        vector<int> curr(W+1,0);
        for(int weight=wt[0];weight<=W;weight++) prev[weight]=val[0];
        for(int i=1;i<n;i++){
            for(int weight=0;weight<=W;weight++){
                int pick=0;
                if(wt[i]<=weight) pick=val[i]+prev[weight-wt[i]];
                int np=prev[weight];
                curr[weight]=max(pick,np);
            }prev=curr;
        }return prev[W];
    }
};