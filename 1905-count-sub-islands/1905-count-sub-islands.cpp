class Solution {
public:
   bool solve(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& grid1,vector<vector<int>>& grid2 ){
      int n= grid1.size();
     int m= grid2[0].size();
    if(i>=n||i<0||j>=m||j<0)return true;
   // if(grid1[i][j]==0)return true;
   int y=grid2[i][j];
    grid2[i][j]=-1;
    bool x= true;
   if(y==1&&grid1[i][j]==0)x=false;
   if(i+1<n&&grid2[i+1][j]==1){
    x=(x&(solve(i+1,j,vis,grid1,grid2)));
   }

    if(i-1>=0&&grid2[i-1][j]==1){
    x=(x&(solve(i-1,j,vis,grid1,grid2)));
   }

 if(j+1<m&&grid2[i][j+1]==1){
    x=(x&(solve(i,j+1,vis,grid1,grid2)));
   }

 if(j-1>=0&&grid2[i][j-1]==1){
    x=(x&(solve(i,j-1,vis,grid1,grid2)));
   }

    return x;
   }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
     
     int n= grid1.size();
     int m= grid2[0].size();
     int ct=0;
     
     vector<vector<int>>vis(n,vector<int>(m,-1));
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid2[i][j]!=1)continue;
                 if(solve(i,j,vis,grid1,grid2))ct++;
        }
     }
    
return ct;


    }
};