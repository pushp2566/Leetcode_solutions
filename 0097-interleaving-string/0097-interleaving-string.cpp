class Solution {
public:
    bool dfs(int i,int j, string & s1,string & s2,string & s3,vector<vector<int>>&dp ){
        int n=s1.size();
        int m=s2.size();
        if(i==n&&j==m&&i+j==s3.size())return true;
  
        if(dp[i][j]!=-1)return dp[i][j];

        int k=i+j;
        if(i==n){
            if(s3[k]==s2[j]){
             dp[i][j]=dfs(i,j+1,s1,s2,s3,dp);
            }
            else{
                return dp[i][j]=0;
            }
        }   
        if(j==m){
            if(s3[k]==s1[i]){
             dp[i][j]=dfs(i+1,j,s1,s2,s3,dp);
            }
            else{
                return dp[i][j]=0;
            }
        }
        bool res=false;
        if(s3[k]==s2[j]){
             res=dfs(i,j+1,s1,s2,s3,dp);
            }

        if(s3[k]==s1[i]){
        res=(res|dfs(i+1,j,s1,s2,s3,dp));
        }
        
        return dp[i][j]=res;

    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       
        dp[n][m]=1;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
             //
                 if(i==n&&j==m&&i+j==s3.size())continue;
                 if(i==n&&j==m)return false;
  
       // if(dp[i][j]!=-1)return dp[i][j];

        int k=i+j;
        if(i==n){
            if(s3[k]==s2[j]){
             dp[i][j]=dp[i][j+1];
            }
            else{
                 dp[i][j]=0;
            }
        }   
        if(j==m){
            if(s3[k]==s1[i]){
             dp[i][j]=dp[i+1][j];
            }
            else{
                 dp[i][j]=0;
            }
        }
        bool res=false;
        if(s3[k]==s2[j]){
             res=dp[i][j+1];
            }

        if(s3[k]==s1[i]){
        res=(res|dp[i+1][j]);
        }
        
         dp[i][j]=res;
             //
            }
        }
        

//  return dfs(0,0,s1,s2,s3,dp)==1;
 return dp[0][0]==1;
        
    }
};