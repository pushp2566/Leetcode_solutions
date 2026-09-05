class Solution {
public:

    int dfs(int i, vector<int>&dp,string &s){
        int n=dp.size();
        if(i>=n)return 1;
        if(dp[i]!=-1)return dp[i];
        if(s[i]=='0')return 0;
        int opt1=dfs(i+1,dp,s);
        int opt2=0;
        if(i<n-1&&s[i]<='2'){
            if(s[i]=='2'&&s[i+1]<='6'){
                opt2=dfs(i+2,dp,s);
            }
            else if(s[i]!='2'){
                opt2=dfs(i+2,dp,s);
            }
        }

        return dp[i]=opt1+opt2;
    }


    int numDecodings(string s) {
        int n=s.size();
       vector<int>dp(n,-1);
       return dfs(0,dp,s);


    }
};