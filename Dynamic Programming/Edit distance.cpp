// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters./
class Solution {
public:
vector<vector<int>> dp;
int recurse(int n,int m,string &word1,string &word2){
    if(n<0) {
        return m+1;
    }if(m<0){
        return n+1;
    }
    if(dp[n][m]!=-1) return dp[n][m];
    if(word1[n]==word2[m]) return dp[n][m]=recurse(n-1,m-1,word1,word2);
    int ins=1+recurse(n-1,m,word1,word2);
    int del=1+recurse(n,m-1,word1,word2);
    int rep=1+recurse(n-1,m-1,word1,word2);
    return dp[n][m]=min({ins,del,rep});
}
    int minDistance(string word1, string word2) {
        // dp.resize(word1.size(),vector<int>(word2.size(),-1));
        int n=word1.size();
        int m=word2.size();
        // return recurse(n-1,m-1,word1,word2);
        dp.resize(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                int ins=1+dp[i-1][j];
                int del=1+dp[i][j-1];
                int rep=1+dp[i-1][j-1];
                dp[i][j]=min({ins,del,rep});
                }
            }
        }return dp[n][m];
    }
};