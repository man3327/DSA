// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9
class Solution {
public:
void recurse(vector<vector<string>> &vec,vector<string>&ans,int row,int n){
    if(row==n){
        vec.push_back(ans);
        return;
    }
    for(int i=0;i<n;i++){
        if(canplace(ans,row,i,n)){
            ans[row][i]='Q';
            recurse(vec,ans,row+1,n);
            ans[row][i]='.';
        }
    }
}bool canplace(vector<string> &ans,int row,int col,int n){
    for(int i=0;i<n;i++){
        if(ans[row][i]=='Q') return false;
    }for(int i=0;i<n;i++){
        if(ans[i][col]=='Q') return false;
    }
    for(int i=row,j=col;i>=0 && j>=0 ;i--,j--){
        if(ans[i][j]=='Q') return false;
    }
    for(int i=row,j=col;j<n && i>=0;j++,i--){
        if(ans[i][j]=='Q') return false;
    }
    return true;
    
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vec;
        vector<string>ans(n,string(n,'.'));
        recurse(vec,ans,0,n);
        return vec;     
    }
};