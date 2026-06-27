// //Alternate Question: - Minimum insertions or deletion to convert s1 to s2
// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

 

// Example 1:

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Example 2:

// Input: word1 = "leetcode", word2 = "etco"
// Output: 4
 

// Constraints:

// 1 <= word1.length, word2.length <= 500
// word1 and word2 consist of only lowercase English letters.
class Solution {
public:
vector<vector<int>> dp;
int recurse(int i,int j,string &word1,string &word2){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(word1[i]==word2[j]) return dp[i][j]=1+recurse(i-1,j-1,word1,word2);
    int nm1=recurse(i-1,j,word1,word2);
    int nm2=recurse(i,j-1,word1,word2);
    return dp[i][j]=max(nm1,nm2);
}
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(),vector<int>(word2.size(),-1));
        int ans=recurse(word1.size()-1,word2.size()-1,word1,word2);
        return (word1.size()-ans) + (word2.size()-ans);
    }
};
//Find Longest Common subsequence cuz that will we our common part ,then subtract the length ,that will give insertions or deletions
