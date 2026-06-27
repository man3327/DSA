/*The Logic is same as Longest common Subsequence 
,just in this question We need to take LCS of the string and its reverse
imagine S="aabaccb"
then its reverse is "bccabaa" ,so LCS of them is "aba" and that 
is also out Longest palindromic Subsequence ,since palindrome is same in reverse order
*/
class Solution {
public:
vector<vector<int>> dp;
int recurse(int i,int j,string &s,string &s2){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s2[j]) return dp[i][j]=1+recurse(i-1,j-1,s,s2);
    int nm=recurse(i-1,j,s,s2);
    int nm2=recurse(i,j-1,s,s2);
    return dp[i][j]=max(nm,nm2);
}
    int longestPalindromeSubseq(string s) {
        dp.resize(s.size(),vector<int>(s.size(),-1));
        string s2(s.begin(),s.end());
        reverse(s2.begin(),s2.end());
        return recurse(s.size()-1,s.size()-1,s,s2);
    }
};
//tabulation and space optimisation is also same as LCS