class Solution {
public:
    int solve(int i ,int j, vector<vector<int>>&dp){
        int n=dp.size();
        int m= dp[0].size();
         if(i>=n || i<0||j<0||j>=m)return 0;
         if(i==n-1 && j==m-1)return 1;
         if(dp[i][j]!=-1)return dp[i][j];
         return dp[i][j]=solve(i+1,j,dp)+solve(i,j+1,dp);
    }
    int uniquePaths(int m, int n) {
        swap(n,m);
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return solve(0,0,dp);

    }
};