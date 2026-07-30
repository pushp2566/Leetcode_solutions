class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            int upto=pq.top().first;
            int i= pq.top().second.first;
            int j= pq.top().second.second;
            pq.pop();
            if(i+1<n){
                int new_upto=max(upto, abs(heights[i][j]-heights[i+1][j]));
                if(dist[i+1][j]>new_upto){
                    dist[i+1][j]=new_upto;
                    pq.push({new_upto,{i+1,j}});
                }
                
            }

            if(i-1>=0){
                int new_upto=max(upto, abs(heights[i][j]-heights[i-1][j]));
                if(dist[i-1][j]>new_upto){
                    dist[i-1][j]=new_upto;
                    pq.push({new_upto,{i-1,j}});
                }
                
            }

            if(j+1<m){
                int new_upto=max(upto, abs(heights[i][j]-heights[i][j+1]));
                if(dist[i][j+1]>new_upto){
                    dist[i][j+1]=new_upto;
                    pq.push({new_upto,{i,j+1}});
                }
                
            }

            if(j-1>=0){
                int new_upto=max(upto, abs(heights[i][j]-heights[i][j-1]));
                if(dist[i][j-1]>new_upto){
                    dist[i][j-1]=new_upto;
                    pq.push({new_upto,{i,j-1}});
                }
                
            }

        }

return  dist[n-1][m-1];

    }
};