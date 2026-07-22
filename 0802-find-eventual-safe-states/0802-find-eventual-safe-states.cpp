class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>ini(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                       adj[graph[i][j]].push_back(i);
                       ini[i]++;
            }
        }
        
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ini[i]==0){
                q.push(i);
            }
        }
            while(!q.empty()){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto child : adj[node]){
                    ini[child]--;
                    if(ini[child]==0){
                        q.push(child);
                    }
                }
            }
sort(ans.begin(),ans.end());
return ans;

    }
};