class Solution {
public:
  bool dfs( int node, int tg, vector<vector<int>>&adj,vector<int>&vis){
    if(node==tg)return true;
    vis[node]=1;
    bool x= false;
    for(int child : adj[node]){
        if(vis[child]==1)continue;
       x=(x|dfs(child,tg,adj,vis));
    }
    return x;
  }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n= numCourses;
        vector<vector<int>>adj(n);
        int m= prerequisites.size();
        for(int i=0;i<m;i++){
 adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<bool>ans;

for(int i=0;i<queries.size();i++){
    vector<int>vis(n,-1);
    bool x= dfs(queries[i][0],queries[i][1],adj, vis);
    ans.push_back(x);
}

return ans;

    }
};