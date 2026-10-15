class Solution {
public: 
    int get(int i,int end,vector<vector<int>>& rides){
        int st=i,ed=rides.size()-1;
        int ans=1e9;
                while(st<=ed){
                    int mid=(st+ed)/2;
                    if(rides[mid][0]>= end){
                        ans=min(ans,mid);
                        ed=mid-1;
                    }
                    else{
                  st=mid+1;
                    }

                }

                return ans;
    }
  long long solve(int i,int n,vector<vector<int>>& rides,vector<long long>&dp){
        int m=rides.size();
        if(i>=m)return 0;
        if(dp[i]!=-1)return dp[i];
        int end=rides[i][1];
        long long cost=rides[i][1]-rides[i][0]+rides[i][2];
        int ind=get(i+1,end,rides);
        long long take=cost+solve(ind,n,rides,dp);
        long long not_take=solve(i+1,n,rides,dp);

        return dp[i]=max(take,not_take);

    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m=rides.size();
        vector<long long>dp(m,-1);
        sort(rides.begin(),rides.end());
        return solve(0,n,rides,dp);
    }
};