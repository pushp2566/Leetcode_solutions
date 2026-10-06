class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        if(i==n-1&&(j<m&&j>=0)){
            return dp[i][j]=matrix[i][j];
        }
        if(i>=n||i<0||j<0||j>=m)return 1e6;
        if(dp[i][j]!=1e9)return dp[i][j];
        int opt1= solve(i+1,j,dp,matrix);
         int opt2= solve(i+1,j-1,dp,matrix);
          int opt3= solve(i+1,j+1,dp,matrix);
          return dp[i][j]=matrix[i][j]+min({opt1,opt2,opt3});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        int ans=1e6;
        for(int i=0;i<m;i++){
           ans=min(ans,solve(0,i,dp,matrix)) ;
        }

        return ans;
    }
};