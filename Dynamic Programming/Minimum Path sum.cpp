// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

 

// Example 1:


// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 200
class Solution {
public:
//Recursion+memoization
vector<vector<int>> dp;
int recurse(int n,int m,vector<vector<int>>& grid){
    if(n==0 && m==0) return grid[0][0];
    int left=INT_MAX,right=INT_MAX;
    if(dp[n][m]!=-1) return dp[n][m];
    if(n>0) left=grid[n][m]+recurse(n-1,m,grid);
    if(m>0) right=grid[n][m]+recurse(n,m-1,grid);
    return dp[n][m]=min(left,right);
}
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<int>(grid[0].size(),-1));
        //tabulation
        int n=grid.size();
        int m=grid[0].size();
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int left=INT_MAX,right=INT_MAX;
                if(i>0) left=grid[i][j]+dp[i-1][j];
                if(j>0) right=grid[i][j]+dp[i][j-1];
                if(left==INT_MAX && right==INT_MAX) dp[i][j]=grid[i][j];
                else dp[i][j]=min(left,right);
            }
        }
        return dp[n-1][m-1];
        return recurse(grid.size()-1,grid[0].size()-1,grid);
    }
};