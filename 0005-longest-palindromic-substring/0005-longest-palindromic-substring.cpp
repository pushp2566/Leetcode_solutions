class Solution {
public:
    bool solve(string &s,int i, int j,vector<vector<int>>&dp){
         int n=s.size();
            if(i<0||j>=n)return false;
            if(i==j)dp[i][j]=1;
            if(j==i+1&&s[i]==s[j])dp[i][j]=1;
            if(dp[i][j]!=-1)return dp[i][j]==1;
            if(s[i]!=s[j]){dp[i][j]=0;
                return false;
            
            }
            return dp[i][j]=solve (s,i+1,j-1,dp);



    }


    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=0;
        string ans="";
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                   if(solve(s,i,j,dp)){
                        if(j-i+1>maxi){
                            maxi =j-i+1;
                            ans=s.substr(i,j-i+1);
                        }
                   }
            }
        }

       
                

 

      return ans;
    }
};