class Solution {
public:

  int solve(int i, int amount,vector<vector<int>>&dp,vector<int>&coins){
    int n=coins.size();
    if(amount<0)return 0;
    if(i>=n){
if(amount==0)return 1;
return 0;
    }
if(dp[i][amount]!=-1)return dp[i][amount];
    int opt1=solve(i,amount-coins[i],dp,coins);
    //int opt2=1+solve(i+1,amount-coins[i],dp,coins);
    int opt3=solve(i+1,amount,dp,coins);


   return dp[i][amount] = opt1+opt3;
   }
  
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
      int ans=solve(0,amount,dp,coins);
     // if(ans>=1e9)return -1;
      return ans;
    }
};