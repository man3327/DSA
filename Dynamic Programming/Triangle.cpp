// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10
 

// Constraints:

// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104
class Solution {
public:
vector<vector<int>>dp;
//TLE 
int recurse(int i,int j,vector<vector<int>>& triangle){
    if(i==triangle.size()-1) return triangle[triangle.size()-1][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int left=recurse(i+1,j+1,triangle)+triangle[i][j];
    int right=recurse(i+1,j,triangle)+triangle[i][j];
    return dp[i][j]=min(left,right);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.resize(triangle.size(),vector<int>(triangle.size(),-1));
        int n=triangle.size();
        //Accepted Tabulation
        for(int j=0;j<=n-1;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int left=triangle[i][j]+dp[i+1][j+1];
                int right=triangle[i][j]+dp[i+1][j];
                dp[i][j]=min(left,right);
            }
        }return dp[0][0];
    }
};
//Space Optimisation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> prev(n,0);
        for(int j=0;j<=n-1;j++){
            prev[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> curr(i+1,0);
            for(int j=i;j>=0;j--){
                int left=triangle[i][j]+prev[j+1];
                int right=triangle[i][j]+prev[j];
                curr[j]=min(left,right);
            }prev=curr;
        }return prev[0];
    }
};