// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

// Constraints:

// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.
class Solution {
public:
vector<vector<bool>> dp;
bool recurse(int n,int m,string &s,string &p){
    if(m<0 && n<0) return true;
    if(m<0) return false;
    if(n<0){
         for(int i=m;i>=0;i--) if(p[i]!='*') return false;
        return true;
    }
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n]==p[m] || p[m]=='?') return dp[n][m]=recurse(n-1,m-1,s,p);
    if(p[m]=='*') return dp[n][m] = recurse(n-1,m,s,p) || recurse(n,m-1,s,p);
    return dp[n][m]=false;
}
    bool isMatch(string s, string p) {
        //dp.resize(s.size(),vector<int>(p.size(),-1));
        dp.resize(s.size()+1,vector<bool>(p.size()+1,0));
        int n=s.size(),m=p.size();
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*') dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j]=false;
                }
            }
        return dp[n][m];
        //return recurse(n-1,m-1,s,p);
    }
};
//Space optimisation
   bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<bool> curr(m+1,false),prev(m+1,false);
        prev[0]=true;
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*') prev[i]=prev[i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') curr[j]=prev[j-1];
                else if(p[j-1]=='*') curr[j] = prev[j] || curr[j-1];
                else curr[j]=false;
                }prev=curr;
            }
        return prev[m];
        
    }