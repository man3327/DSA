// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

// Example 1:


// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.
// Example 2:


// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100
//Recursion+memoization
class Solution {
public:
vector<vector<int>> dp;
int recurse(int n,int m,vector<vector<int>>& A){
    if(m<0 || m>=A.size()) return INT_MAX;
    if(dp[n][m]!=INT_MIN) return dp[n][m];
     if(n==0) return A[0][m];
        int below=recurse(n-1,m,A);
        int dialeft=recurse(n-1,m-1,A);
        int diaright=recurse(n-1,m+1,A);
        return dp[n][m]=min(min(below,dialeft),diaright)+A[n][m];
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        dp.resize(matrix.size(),vector<int>(matrix.size(),INT_MIN));
        //tabulation
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int dialeft=INT_MAX,diaright=INT_MAX;
                int below=dp[i-1][j];
                if(j-1>=0)dialeft=dp[i-1][j-1];
                if(j+1<n)diaright=dp[i-1][j+1];
                dp[i][j]=min(min(below,dialeft),diaright)+matrix[i][j];
            }
        }
        //answer is the minimum of last row
        for(int j=0;j<n;j++) mini=min(mini,dp[n-1][j]);
        return mini;
    }
};
//Space OptimisationO(n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<int> prev(n,0);
        for(int j=0;j<n;j++){
            prev[j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                int dialeft=INT_MAX,diaright=INT_MAX;
                int below=prev[j];
                if(j-1>=0)dialeft=prev[j-1];
                if(j+1<n)diaright=prev[j+1];
                curr[j]=min(min(below,dialeft),diaright)+matrix[i][j];
            }prev=curr;
        }
        for(int j=0;j<n;j++) mini=min(mini,prev[j]);
        return mini;
    }
};

