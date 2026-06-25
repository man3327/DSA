// Given a set of items, each with a weight and a value, represented by the array wt[] and val[] respectively. Also, a knapsack with a weight limit capacity.
// Your task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.

// Note: Each item can be taken any number of times.

// Examples:

// Input: val[] = [1, 1], wt[] = [2, 1], capacity = 3
// Output: 3
// Explanation: The optimal choice is to pick the 2nd element 3 times.
// Input: val[] = [10, 40, 50, 70], wt[] = [1, 3, 4, 5], capacity = 8
// Output: 110
// Explanation: The optimal choice is to pick the 2nd element and the 4th element.
// Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
// Output: 0
// Explanation: We can't pick any element. Hence, total profit is 0.
// Constraints:
// 1 ≤ val.size() = wt.size() ≤ 1000
// 1 ≤ capacity ≤ 1000
// 1 ≤ val[i], wt[i] ≤ 100
class Solution {
  public:
  vector<vector<int>> dp;
  int recurse(int n,int cap,vector<int>& val,vector<int>& wt){
      if(n==0){
          return val[n]*(cap/wt[n]);
      }
      if(dp[n][cap]!=-1) return dp[n][cap];
      int pick=0;
      if(cap-wt[n]>=0) pick=val[n]+recurse(n,cap-wt[n],val,wt);
      int np=recurse(n-1,cap,val,wt);
      return dp[n][cap]=max(pick,np);
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        //dp.resize(n,vector<int>(capacity+1,-1));
        //return recurse(n-1,capacity,val,wt);
        dp.resize(n,vector<int>(capacity+1,0));
        for(int i=0;i<=capacity;i++){
            dp[0][i]=val[0]*(i/wt[0]);
        }for(int i=1;i<n;i++){
            for(int W=0;W<=capacity;W++){
                int pick=0;
                if(W-wt[i]>=0) pick=val[i]+dp[i][W-wt[i]];
                int np=dp[i-1][W];
                dp[i][W]=max(pick,np);
            }
        }return dp[n-1][capacity];
    }
};
//space optimisation
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<int> prev(capacity+1,0),curr(capacity+1,0);
        for(int i=0;i<=capacity;i++){
            prev[i]=val[0]*(i/wt[0]);
        }for(int i=1;i<n;i++){
            for(int W=0;W<=capacity;W++){
                int pick=0;
                if(W-wt[i]>=0) pick=val[i]+curr[W-wt[i]];
                int np=prev[W];
                curr[W]=max(pick,np);
            }prev=curr;
        }return prev[capacity];
    }
};
//further optimisation to only 1 array
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<int> prev(capacity+1,0);
        for(int i=0;i<=capacity;i++){
            prev[i]=val[0]*(i/wt[0]);
        }for(int i=1;i<n;i++){
            for(int W=0;W<=capacity;W++){
                int pick=0;
                if(W-wt[i]>=0) pick=val[i]+prev[W-wt[i]];
                int np=prev[W];
                prev[W]=max(pick,np);
            }
        }return prev[capacity];
    }
};