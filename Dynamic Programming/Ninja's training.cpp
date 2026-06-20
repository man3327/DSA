// A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting practice. The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.
// Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.
// Example 1
// Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]
// Output: 210
// Explanation:
// Day 1: fighting practice = 70
// Day 2: stealth training = 50
// Day 3: fighting practice = 90
// Total = 70 + 50 + 90 = 210
// This gives the optimal points.

// Example 2
// Input: matrix = [[70, 40, 10], [180, 20, 5], [200, 60, 30]]
// Output: 290
// Explanation:
// Day 1: running = 70
// Day 2: stealth training = 20
// Day 3: running = 200
// Total = 70 + 20 + 200 = 290
// This gives the optimal points.
class Solution {
public:
vector<vector<int>> dp;
int recurse(int idx,vector<vector<int>>& matrix,int last){
    if(idx==0) {
        int maxi=-1;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=max(maxi,matrix[0][i]);
            }
        }return maxi;
    }if(dp[idx][last]!=-1) return dp[idx][last];
    int maxi=-1;
    for(int i=0;i<=2;i++){
        if(i!=last){
        maxi=max(maxi,matrix[idx][i]+recurse(idx-1,matrix,i));
        }
    }return dp[idx][last]=maxi;
}
    int ninjaTraining(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(),vector<int>(4,-1));
        return recurse(matrix.size()-1,matrix,3);
    }
};
//Tabulation
class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(4,-1));
        dp[0][0]=max(matrix[0][1],matrix[0][2]);
        dp[0][1]=max(matrix[0][0],matrix[0][2]);
        dp[0][2]=max(matrix[0][1],matrix[0][0]);
        dp[0][3]=max({matrix[0][1],matrix[0][2],matrix[0][0]});
        for(int i=1;i<matrix.size();i++){
            for(int last=0;last<4;last++){
                dp[i][last]=0;
                for(int task=0;task<3;task++){
                    if(task!=last){
                        dp[i][last]=max(dp[i][last],matrix[i][task]+dp[i-1][task]);
                    }
                }
            }
        }return dp[matrix.size()-1][3];

    }
};