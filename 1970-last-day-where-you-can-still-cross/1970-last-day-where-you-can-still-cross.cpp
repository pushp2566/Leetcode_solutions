class Solution {
public:
  
  class dsu{
    public:
     vector<vector<int>>size;
     vector<vector<pair<int,int>>>par;
     
        dsu(int n, int m){
       size.resize(n+2, vector<int>(m+2, 1));

par.resize(n+2, vector<pair<int,int>>(m+2));
            for(int i=0;i<n+2;i++){
                for(int j=0;j<m+2;j++){
                 par[i][j]={i,j};
                }
            }
        }
            void unite(int i, int j , int k , int l ){
                pair<int,int> a= find(i,j);
                pair<int,int> b= find(k,l);
                if(a==b)return;
                        if(size[a.first][a.second]>=size[b.first][b.second]){
                            par[b.first][b.second]=a;
                            size[a.first][a.second]+=size[b.first][b.second];
                        }
                        else{
                            par[a.first][a.second]=b;
                            size[b.first][b.second]+=size[a.first][a.second];
                        }
            }


            pair<int,int>find(int i, int j){
                if(par[i][j]==pair<int,int>{i,j})return {i,j};
                return par[i][j]=find(par[i][j].first,par[i][j].second);
                
            }
  };




    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans=0;
         int n=row,m=col;
        dsu u(n,m);
       
      vector<vector<int>> grid(n, vector<int>(m, 1));
        for(int j=0;j<m;j++){
            u.unite(0,j,n,m);
        }

          for(int j=0;j<m;j++){
            u.unite(n-1,j,n+1,m+1);
        }

        int curr=m*n;
 
 for(int i=cells.size()-1;i>=0;i--){
if(u.find(n,m)==u.find(n+1,m+1)){
    return curr;
}

int x= cells[i][0]-1, y=cells[i][1]-1;
grid[x][y]=0;
curr--;

if(x+1<n&&grid[x+1][y]==0){
    u.unite(x,y,x+1,y);
}
if(x-1>=0&&grid[x-1][y]==0){
    u.unite(x,y,x-1,y);
}
if(y+1<m&&grid[x][y+1]==0){
    u.unite(x,y,x,y+1);
}
if(y-1>=0&&grid[x][y-1]==0){
    u.unite(x,y,x,y-1);
}

 }


return 0;


    }
};