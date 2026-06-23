class Solution{
	public:
    vector<vector<int>> dp;
    int recurse(int n,int target,vector<int>&arr){
        if(target==0) return 1;
        if(n<0){
            return target==0;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        int pick=0;
        if(target-arr[n]>=0) pick=recurse(n-1,target-arr[n],arr);
        int np=recurse(n-1,target,arr);
        return dp[n][target]=(pick+np);
    }
	int perfectSum(vector<int>&arr, int k){
        // dp.resize(arr.size(),vector<int>(k+1,-1));
        dp.resize(arr.size(),vector<int>(k+1,0));
        int n=arr.size();
        if (arr[0] == 0)
            dp[0][0] = 2; // {} and {0}
        else {
            dp[0][0] = 1; // {}
            if (arr[0] <= k)
                dp[0][arr[0]] = 1;
        }
       for(int i=1;i<n;i++){
        for(int tar=0;tar<=k;tar++){
            int pick=0;
            if(tar-arr[i]>=0) pick=dp[i-1][tar-arr[i]];
            int np=dp[i-1][tar];
            dp[i][tar]=(pick+np);
        }
       }return dp[n-1][k];
        return recurse(arr.size()-1,k,arr);
	}
};
//Space optimised
class Solution{
	public:
	int perfectSum(vector<int>&arr, int k){
        vector<int> prev(k+1,0);
        vector<int> curr(k+1,0);
        int n=arr.size();
        if (arr[0] == 0)
            prev[0] = 2; // {} and {0}
        else {
            prev[0] = 1; // {}
            if (arr[0] <= k)
                prev[arr[0]] = 1;
        }
       for(int i=1;i<n;i++){
        for(int tar=0;tar<=k;tar++){
            int pick=0;
            if(tar-arr[i]>=0) pick=prev[tar-arr[i]];
            int np=prev[tar];
            curr[tar]=(pick+np);
        }prev=curr;
       }return prev[k];
	}
};