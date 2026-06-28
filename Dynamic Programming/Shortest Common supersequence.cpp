// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.
// Example 2:

// Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
// Output: "aaaaaaaa"
 

// Constraints:

// 1 <= str1.length, str2.length <= 1000
// str1 and str2 consist of lowercase English letters.
//SOL:- THE INTUITION IS SAME AS LCS TAKE LONGEST COMMON SUBSEQUENCE BUT INSTEAD OF SKIPPING WE ADD THE STR1 ELEMENTS AND STR2 ELEMENTS TOO SEPERATELY AND LCS ONCE
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size() + 1,
                               vector<int>(str2.size() + 1, 0));
        for (int i = 1; i <= str1.size(); i++) {
            for (int j = 1; j <= str2.size(); j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else {
                    int nm1 = dp[i - 1][j];
                    int nm2 = dp[i][j - 1];
                    dp[i][j] = max(nm1, nm2);
                }
            }
        }int n=str1.size();
        int m=str2.size();
        string ans="";
        while(n>0 && m>0){
            if(str1[n-1]==str2[m-1]){
                ans+=str1[n-1];
                n--;m--;
            }else if(dp[n][m-1]>dp[n-1][m]){
                ans+=str2[m-1];
                m--;
            }else{
                ans+=str1[n-1];
                n--;
                }
        }
        while(n>0){
            ans+=str1[n-1];
            n--;
        }
        while(m>0) {
            ans+=str2[m-1];
            m--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};