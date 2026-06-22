// Given an array arr of n integers and an integer target, determine if there is a subset of the given array with a sum equal to the given target.


// Example 1

// Input: arr = [1, 2, 7, 3], target = 6

// Output: True

// Explanation: There is a subset (1, 2, 3) with sum 6.

// Example 2

// Input: arr = [2, 3, 5], target = 6

// Output: False

// Explanation: There is no subset with sum 6.
class Solution{   
public:
vector<vector<int>> dp;
bool recurse(int n,vector<int>& arr,int target){
    if(target==0) return true;
    if(n==0){
        if(target-arr[0]==0) return true;
        else return false;
    }
    if(dp[n][target]!=-1) return dp[n][target];
    bool pick=false;
    if(target>=arr[n]) pick=recurse(n-1,arr,target-arr[n]);
    bool np=recurse(n-1,arr,target);
    return dp[n][target]=pick||np;
}
    bool isSubsetSum(vector<int>arr, int target){
        dp.resize(arr.size(),vector<int>(target+1,-1));
        return recurse(arr.size()-1,arr,target);
    }
};
//tabulation
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int target){
        vector<vector<int>> dp(arr.size(),vector<int>(target+1,0));
        int n=arr.size();
        if(arr[0] <= target) dp[0][arr[0]]=true;
        for(int i=0;i<arr.size();i++){
            dp[i][0]=true;
        }
        for(int i=1;i<arr.size();i++){
            for(int j=1;j<=target;j++){
                bool np=dp[i-1][j];
                bool pick=false;
                if(j-arr[i]>=0)pick=dp[i-1][j-arr[i]];
                dp[i][j]=np||pick;
            }
        }
        return dp[n-1][target];
    }
};
//space optimisation O(target)
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int target){
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        int n=arr.size();
        if(arr[0] <= target) prev[arr[0]]=true;
        prev[0]=true;
        for(int i=1;i<arr.size();i++){
            curr[0]=true;
            for(int j=1;j<=target;j++){
                bool np=prev[j];
                bool pick=false;
                if(j-arr[i]>=0)pick=prev[j-arr[i]];
                curr[j]=np||pick;
            }prev=curr;
        }
        return prev[target];
    }
};