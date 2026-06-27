// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

 

// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.
// Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".
// Example 3:

// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.
class Solution {
public:
vector<vector<int>> dp;
int recurse(int i,int j,string &s, string &s2){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==s2[j]) return dp[i][j]=1+recurse(i-1,j-1,s,s2);
    int np1=recurse(i-1,j,s,s2);
    int np2=recurse(i,j-1,s,s2);
    return dp[i][j]=max(np1,np2);
}
    int minInsertions(string s) {
        dp.resize(s.size(),vector<int>(s.size(),-1));
        string s2(s.begin(),s.end());
        reverse(s2.begin(),s2.end());
        int ans = recurse(s.size()-1,s.size()-1,s,s2);
        return s.size()-ans;
    }
};