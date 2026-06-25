// Given a rod of length N inches and an array price[] where price[i] denotes the value of a piece of rod of length i inches (1-based indexing). Determine the maximum value obtainable by cutting up the rod and selling the pieces. Make any number of cuts, or none at all, and sell the resulting pieces.


// Example 1

// Input: price = [1, 6, 8, 9, 10, 19, 7, 20], N = 8

// Output: 25

// Explanation: Cut the rod into lengths of 2 and 6 for a total price of 6 + 19= 25.

// Example 2

// Input: price = [1, 5, 8, 9], N = 4

// Output: 10

// Explanation: Cut the rod into lengths of 2 and 2 for a total price of 5 + 5 = 10.
class Solution{
  public:
  vector<vector<int>> dp;
  int recurse(int n,int idx,vector<int>& cuts){
    if(idx==0) return n*cuts[idx];
    if(dp[idx][n]!=-1) return dp[idx][n];
    int pick=INT_MIN;
    int rodlength=idx+1;
    if(n>=rodlength) pick=cuts[idx]+recurse(n-rodlength,idx,cuts);
    int np=recurse(n,idx-1,cuts);
    return dp[idx][n]=max(pick,np);
}
    int rodCutting(vector<int> price, int n) {
        //dp.resize(price.size(),vector<int>(n+1,-1));
        //return recurse(n,price.size()-1,price);
        dp.resize(price.size(),vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=i*price[0];
        }
        for(int i=1;i<price.size();i++){
            for(int cut=0;cut<=n;cut++){
                int pick=INT_MIN;
                if(cut>=(i+1)) pick=price[i]+dp[i][cut-(i+1)];
                int np=dp[i-1][cut];
                dp[i][cut]=max(pick,np);
            }
        }return dp[price.size()-1][n];
    }
};
//space optimisation
class Solution{
  public:
    int rodCutting(vector<int> price, int n) {
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int i=0;i<=n;i++){
            prev[i]=i*price[0];
        }
        for(int i=1;i<price.size();i++){
            for(int cut=0;cut<=n;cut++){
                int pick=INT_MIN;
                if(cut>=(i+1)) pick=price[i]+curr[cut-(i+1)];
                int np=prev[cut];
                curr[cut]=max(pick,np);
            }prev=curr;
        }return prev[n];
    }
};
//optimisation to 1 array
class Solution{
  public:
    int rodCutting(vector<int> price, int n) {
        vector<int> prev(n+1,0);
        for(int i=0;i<=n;i++){
            prev[i]=i*price[0];
        }
        for(int i=1;i<price.size();i++){
            for(int cut=0;cut<=n;cut++){
                int pick=INT_MIN;
                if(cut>=(i+1)) pick=price[i]+prev[cut-(i+1)];
                int np=prev[cut];
                prev[cut]=max(pick,np);
            }
        }return prev[n];
    }
};
