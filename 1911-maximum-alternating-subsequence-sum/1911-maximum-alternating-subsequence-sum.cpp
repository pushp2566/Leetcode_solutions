class Solution {
public: 
    long long solve(int i,int dec,vector<int>& nums,vector<vector<long long >>&dp){
         int n=nums.size();
        if(i>=n)return 0;

        if(dp[i][dec]!=-1)return dp[i][dec];
       long long nt=solve(i+1,dec,nums,dp);
       long long take=0;
       if(dec==0){
             take=-1*nums[i]+solve(i+1,1-dec,nums,dp);
       }
       else{
        take=1*nums[i]+solve(i+1,1-dec,nums,dp);
       }

       return dp[i][dec]=max(take,nt);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long >>dp(n,vector<long long >(2,-1));
        return solve(0,1,nums,dp);

    }
};