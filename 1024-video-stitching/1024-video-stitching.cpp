bool comp(vector<int>a,vector<int>b){
    if(a[0]!=b[0])return a[0]<b[0];
    return a[1]>b[1];
}

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end(),comp);
       // int ct=0;
       // int last=-1,curr=0;
        int n=clips.size();
        if(clips[0][0]>0)return-1 ;
        int last=clips[0][1];
    

        int i=1;
        int ct=1;
         if(last>=time)return ct;
        while(i<n){
            int curr=-1;
            ct++;
            while(i<n&&clips[i][0]<=last){
                curr=max(curr,clips[i][1]);
                i++;
            }
            if(curr>=time)return ct;
            if(curr<=last)return -1;
            last=curr;
        }

if(last<time)return -1;
return ct;

    }
};