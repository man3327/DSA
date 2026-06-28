// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.

 

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
 

// Constraints:

// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.
class Solution {
public:
vector<vector<double>> dp;
int recurse(int n,int m,string &s,string &t){
    if(m<0) return 1;
    if(n<0)return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n]==t[m]) {
    return dp[n][m]=( recurse(n-1,m-1,s,t) +recurse(n-1,m,s,t));
    }
    return dp[n][m]=recurse(n-1,m,s,t);
}
    int numDistinct(string s, string t) {
       // dp.resize(s.size(),vector<int>(t.size(),-1));
       dp.resize(s.size()+1,vector<double>(t.size()+1,0));
       for(int i=0;i<s.size();i++) dp[i][0]=1;
        int n=s.size();
        int m=t.size();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) {
                    dp[i][j]=dp[i-1][j-1] +dp[i-1][j];
                }else dp[i][j]=dp[i-1][j];
            }
        }return (int)dp[n][m];
        //return recurse(n-1,m-1,s,t);
    }
};
//space optimisaation
class Solution {
public:
    int numDistinct(string s, string t) {
       vector<double> curr(t.size()+1,0),prev(t.size()+1,0);//we just used double here to  avoid overflow
       prev[0]=1;curr[0]=1;
        int n=s.size();
        int m=t.size();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) {
                    curr[j]=(prev[j-1] +prev[j]);
                }else curr[j]=prev[j];
            }prev=curr;
        }return (int)prev[m];//then we converted the double to int since ans was expected in int
    }
};