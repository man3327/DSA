// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8
class Solution {
public:
void recurse(string s,int n ,vector<string> &vec,int open,int close){
    if(s.size()==2*n){
        vec.push_back(s);
        return;
    }
    
    if(open<n)recurse(s+'(',n,vec,open+1,close);
    if(close<open)recurse(s+')',n,vec,open,close+1);
}
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        recurse("",n,vec,0,0);
        return vec;
    }
};