class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>start;
        vector<int>end;
        for(int i=0;i<n;i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }

        sort(start.begin(),start.end());
         sort(end.begin(),end.end());
         int ct=0;
          int i=0,j=0;
          int ans=0;
          while(i<n){
               if(start[i]<=end[j]){
                ct++;
                ans=max(ans,ct);
                i++;
               }
               else{
                ct--;
                j++;
               }
          }

          return ans;

    }
};