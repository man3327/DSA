// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
class Solution {
public:
    void recurse(vector<int>& c,vector<vector<int>> &vec,vector<int> &res,int target,int start){
    if(target==0){
        vec.push_back(res);
        return;
    }
        for(int i=start;i<c.size();i++){
            if(i>start && c[i]==c[i-1]) continue;
            if(c[i]>target) break;
            res.push_back(c[i]);
            recurse(c,vec,res,target-c[i],i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> vec;
        vector<int> res;
        recurse(candidates,vec,res,target,0);
        return vec;
    }
};