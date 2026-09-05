class Solution {
public:
    bool dfs(int i,int j, string & s1,string & s2,string & s3,vector<vector<int>>&dp ){
        int n=s1.size();
        int m=s2.size();
        if(i==n&&j==m&&i+j==s3.size())return true;
         if(i==n&&j==m)return false;
  
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
        if(m+n!=s3.size())return false;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       
       // dp[n][m]=1;
        vector<int>prev(m+1,0);
        prev[m]=1;

        
            for(int j=m-1;j>=0;j--){
                int k=n+j;
            if(s3[k]==s2[j]){
             prev[j]=prev[j+1];
            }
            else{
              prev[j]=0;
            }
            }
              
        
        for(int i=n-1;i>=0;i--){
            vector<int>curr(m+1,0);
            for(int j=m;j>=0;j--){
             //
                 if(i==n&&j==m&&i+j==s3.size())continue;
                
  
       // if(dp[i][j]!=-1)return dp[i][j];

        int k=i+j;
        // if(i==n){
        //     if(s3[k]==s2[j]){
        //      dp[i][j]=dp[i][j+1];
        //     }
        //     else{
        //          dp[i][j]=0;
        //     }
        // }   
        if(j==m){
            if(s3[k]==s1[i]){
             curr[j]=prev[j];
            }
            else{
                curr[j]=0;
            }
        }
        int res=0;
        if(s3[k]==s2[j]){
             res=curr[j+1];
            }

        if(s3[k]==s1[i]){
        res=(res|prev[j]);
        }
        
         curr[j]=res;
             //
            }
            prev=curr;
        }
        

//  return dfs(0,0,s1,s2,s3,dp)==1;
 return prev[0]==1;
        
    }
};