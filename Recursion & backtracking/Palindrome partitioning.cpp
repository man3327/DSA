// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.
class Solution {
public:
bool ispalindrome(string temp){
    int l=0,r=temp.size()-1;
    while(l<r){
        if(temp[l]!=temp[r]) return false;
        l++;r--;
    }return true; 
}
    void recurse(vector<vector<string>> &vec,vector<string> &res,string &s,int start){
        if(s.size()==start){
            vec.push_back(res);
            return;
        }
        string temp="";
        for(int i=start;i<s.size();i++){
            temp+=s[i];
            if(ispalindrome(temp)){
                res.push_back(temp);
                recurse(vec,res,s,i+1);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> vec;
        vector<string> res;
        recurse(vec,res,s,0);
        return vec;
    }
};