class Solution {
public:
vector<int> dp;
int recurse(int idx,vector<int>& heights){
    if(dp[idx]!=-1) return dp[idx];
    if(idx==0) return 0;
    if(idx<0) return INT_MAX;
    int one=INT_MAX,two=INT_MAX;
    if(idx>=1) one=recurse(idx-1,heights)+abs(heights[idx]-heights[idx-1]);
    if(idx>=2) two=recurse(idx-2,heights)+abs(heights[idx]-heights[idx-2]);
    return dp[idx]=min(one,two);
}
    int frogJump(vector<int>& heights) {
        dp.resize(heights.size()+1,-1);
        return recurse(heights.size()-1,heights);

    }
};