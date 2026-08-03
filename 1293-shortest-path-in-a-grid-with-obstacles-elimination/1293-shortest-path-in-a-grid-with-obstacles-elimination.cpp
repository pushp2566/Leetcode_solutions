class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
      vector<vector<vector<int>>> dist(
    n,
    vector<vector<int>>(m, vector<int>(k + 2, 1e9))
);
        dist[0][0][0]=0;
        queue<vector<int>>q;
        q.push({0,0,0,0});
        // cost, i , j, stops
        while(!q.empty()){
            int cost=q.front()[0];
             int i=q.front()[1];
              int j=q.front()[2];
               int stops=q.front()[3];
               q.pop();
                if(stops>=k+1)continue;
                if(i==n-1&&j==m-1)return cost;
                if(i+1<n){
                    if(grid[i+1][j]==1){
                                  if(dist[i+1][j][stops+1]>cost+1){

                                    dist[i+1][j][stops+1]=cost+1;
                                    q.push({cost+1,i+1,j,stops+1});
                                  }
                    }
                    else{
                                     
                                     if(dist[i+1][j][stops]>cost+1){

                                    dist[i+1][j][stops]=cost+1;
                                    q.push({cost+1,i+1,j,stops});
                                  }


                    }
                }
                
                /////
                if(i-1>=0){
                    if(grid[i-1][j]==1){
                                  if(dist[i-1][j][stops+1]>cost+1){

                                    dist[i-1][j][stops+1]=cost+1;
                                    q.push({cost+1,i-1,j,stops+1});
                                  }
                    }
                    else{
                                     
                                     if(dist[i-1][j][stops]>cost+1){

                                    dist[i-1][j][stops]=cost+1;
                                    q.push({cost+1,i-1,j,stops});
                                  }


                    }
                }


                ////////



                if(j+1<m){
                    if(grid[i][j+1]==1){
                                  if(dist[i][j+1][stops+1]>cost+1){

                                    dist[i][j+1][stops+1]=cost+1;
                                    q.push({cost+1,i,j+1,stops+1});
                                  }
                    }
                    else{
                                     
                                     if(dist[i][j+1][stops]>cost+1){

                                    dist[i][j+1][stops]=cost+1;
                                    q.push({cost+1,i,j+1,stops});
                                  }


                    }
                }
                //////


                if(j-1>=0){
                    if(grid[i][j-1]==1){
                                  if(dist[i][j-1][stops+1]>cost+1){

                                    dist[i][j-1][stops+1]=cost+1;
                                    q.push({cost+1,i,j-1,stops+1});
                                  }
                    }
                    else{
                                     
                                     if(dist[i][j-1][stops]>cost+1){

                                    dist[i][j-1][stops]=cost+1;
                                    q.push({cost+1,i,j-1,stops});
                                  }


                    }
                }
               

        }

return -1;
        
    }
};