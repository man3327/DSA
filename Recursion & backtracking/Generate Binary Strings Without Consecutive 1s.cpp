// Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.



// A binary string is a string consisting only of characters '0' and '1'.


// Example 1

// Input: n = 3

// Output: ["000", "001", "010", "100", "101"]

// Explanation: All strings are of length 3 and do not contain consecutive 1s.

// Example 2

// Input: n = 2

// Output: ["00", "01", "10"]
class Solution {
public:
void recurse(vector<string> &vec,string s,int n,int idx,bool prev){
    if(idx==n){
        vec.push_back(s);
        return;
    }
    recurse(vec,s+'0',n,idx+1,false);
    if(!prev) recurse(vec,s+'1',n,idx+1,true);
}
    vector<string> generateBinaryStrings(int n) {
        vector<string> vec;
        recurse(vec,"",n,0,false);
        return vec;
    }
};
