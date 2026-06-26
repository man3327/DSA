// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.
 

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.
class Solution {
public:
vector<vector<int>> dp;
int recurse(int idx,int idx2,string &b,string &a){
    if(idx==0 || idx2==0) return 0;
    if(dp[idx][idx2]!=-1) return dp[idx][idx2];
    if(a[idx-1]==b[idx2-1]) return dp[idx][idx2]=1+recurse(idx-1,idx2-1,b,a);
    int nm1=recurse(idx-1,idx2,b,a);
    int nm2=recurse(idx,idx2-1,b,a);
    return dp[idx][idx2]=max(nm1,nm2);
}
    int longestCommonSubsequence(string text1, string text2) {
        // dp.resize(text1.size()+1,vector<int>(text2.size()+1,-1));
        // return recurse(text1.size(),text2.size(),text2,text1);
        dp.resize(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int idx=1;idx<=text1.size();idx++){
            for(int idx2=1;idx2<=text2.size();idx2++){
                if(text1[idx-1]==text2[idx2-1]) {
                    dp[idx][idx2]=1+dp[idx-1][idx2-1];
                }else{
                int nm1=dp[idx-1][idx2];
                int nm2=dp[idx][idx2-1];
                dp[idx][idx2]=max(nm1,nm2);
                }
            }
        }return dp[text1.size()][text2.size()];
    }
};
//Space optimisation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prev(text2.size()+1,0),curr(text2.size()+1,0);
        for(int idx=1;idx<=text1.size();idx++){
            for(int idx2=1;idx2<=text2.size();idx2++){
                if(text1[idx-1]==text2[idx2-1]) {
                    curr[idx2]=1+prev[idx2-1];
                }else{
                    int nm1=prev[idx2];
                    int nm2=curr[idx2-1];
                    curr[idx2]=max(nm1,nm2);
                }
            }prev=curr;
        }return prev[text2.size()];
    }
};
//To print the subsequence 
string ans="";
        while(n>0 && m>0){
            if(text1[n-1]==text2[m-1]){
                ans+=text1[n-1];
                n--;m--;
            }else if(dp[n-1][m]>dp[n][m-1]){
                n--;
            }else{
                m--;
            }
        }cout<<ans;