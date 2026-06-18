// Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

// Note that operands in the returned expressions should not contain leading zeros.

// Note that a number can contain multiple digits.
// Example 1:
// Input: num = "123", target = 6
// Output: ["1*2*3","1+2+3"]
// Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
// Example 2:

// Input: num = "232", target = 8
// Output: ["2*3+2","2+3*2"]
// Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
// Example 3:

// Input: num = "3456237490", target = 9191
// Output: []
// Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
 

// Constraints:

// 1 <= num.length <= 10
// num consists of only digits.
// -231 <= target <= 231 - 1
class Solution {
public:
void recurse(vector<string>&vec,string s,string num,int target,int idx,long long expr,long long prev){
    if(idx==num.size()){
        if(expr==target) vec.push_back(s);
        return;
    }long long curr=0;
    string temp="";
    for(int j=idx;j<num.size();j++){
        if(j>idx && num[idx]=='0')break;
        temp+=num[j];
        curr=curr*10+num[j]-'0';
    if(idx==0) recurse(vec,s+temp,num,target,j+1,curr,curr);
    else{
    recurse(vec,s+'*'+temp,num,target,j+1,expr-prev+prev*curr,prev*curr);
    recurse(vec,s+'+'+temp,num,target,j+1,expr+curr,curr);
    recurse(vec,s+'-'+temp,num,target,j+1,expr-curr,-curr);
    
    }}
}
    vector<string> addOperators(string num, int target) {
        vector<string> vec;
        recurse(vec,"",num,target,0,0,0);
        return vec;
    }
};