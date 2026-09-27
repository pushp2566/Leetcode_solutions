class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n= nums.size();
        map<pair<int,int>,int>mp;
        
                int ans=0;
                for(int i=0;i<n-1;i++){
                int left=min(nums[i],nums[i+1]);
                int right=max(nums[i],nums[i+1]);
                mp[{left,right}]++;
                if(left==right)ans++;
                }
                

                int x=0;

                for(auto it=mp.begin();it!=mp.end();it++){
                        int curr=it->second;
                        int left=0,right=0;
                        if(it->first.first==it->first.second){
                           continue;
                        }
                        if(mp.find({it->first.first,it->first.first})!=mp.end()){
                            left+=mp[{it->first.first,it->first.first}];
                        }
                         if(mp.find({it->first.second,it->first.second})!=mp.end()){
                            right+=mp[{it->first.second,it->first.second}];
                        }
                      //  curr=curr+left+right;
                       // ans=max(ans,curr);
                       x=max(x,curr);
                }

                return ans+x;
    }
};