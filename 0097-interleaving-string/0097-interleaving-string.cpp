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
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return dfs(0,0,s1,s2,s3,dp);
        


        
    }
};