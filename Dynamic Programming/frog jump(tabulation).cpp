class Solution {
public:
    int frogJump(vector<int>& heights) {
        vector<int> dp(heights.size(),0);
        dp[0]=0;
        for(int i=1;i<heights.size();i++){
            int one=dp[i-1]+abs(heights[i]-heights[i-1]);
            int two=INT_MAX;
            if(i>1) two=dp[i-2]+abs(heights[i]-heights[i-2]);
            dp[i]=min(one,two);
        }return dp[heights.size()-1];
    }
};