class Solution {
public:
     int solve(int i,int  j, string &   s, string &p, vector<vector<int>>&dp){
            int n=s.size();
        int m=p.size();
        if(i==n&&j==m)return 1;
        //if(i==n&&j==m-2&&p[j+1]=='*')return 1;
        if(i==n){
            while(j<m-1){
                 if(p[j+1]=='*')j+=2;
                 else return 0;
            }
            if(p[m-1]!='*')return 0;
            return 1;
        }
        if(i==n||j==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int res=0;
        if(j<m-1&&p[j+1]=='*'){
            if(s[i]==p[j]){
                       res= (res|solve(i+1,j+2,s,p,dp));
                       res= (res|solve(i,j+2,s,p,dp));
                       res= (res|solve(i+1,j,s,p,dp));

            }
            else if(p[j]=='.'){
                   res= (res|solve(i+1,j+2,s,p,dp));
                       res= (res|solve(i,j+2,s,p,dp));
                       res= (res|solve(i+1,j,s,p,dp));
            }
            else{
                 res= (res|solve(i,j+2,s,p,dp));
                 //res= (res|solve(i+1,j+2,s,p,dp));
                // res= (res|solve(i,j+2,s,p,dp));
            }
               
                 
        }
        else{
            if(p[j]=='.'){
                    res= (res|solve(i+1,j+1,s,p,dp));
            }
            else if(s[i]==p[j]){
                 res= (res|solve(i+1,j+1,s,p,dp));
            }
            else{
                res=0;
            }


        }

return dp[i][j]=res;

     }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s,p,dp)==1;

    }
};