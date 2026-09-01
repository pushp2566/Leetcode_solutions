class Solution {
public:
    // bool comp(vector<int>a, vector<int>b){
    //     return a[1]<=b[1];
    // }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       int n=trips.size();
       vector<pair<int,int>>start;
        vector<pair<int,int>>end;
        for(int i=0;i<n;i++){
            start.push_back({trips[i][1],trips[i][0]});
            end.push_back({trips[i][2],trips[i][0]});
        }
       sort(start.begin(),start.end());
       sort(end.begin(),end.end());
       int ct=0;
       int i=0;int j=0;
        while(i<n){
            if(end[j].first<=start[i].first){
                ct-=end[j].second;
                j++;
            }
            else{
                ct+=start[i].second;
                i++;
            }

            if(ct> capacity)return false;
        }

return true;
     
    }
};