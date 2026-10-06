class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long  ans=0;
        long long  curr=0;
        int i=0,j=0;
        map<int,int>mp;
        while(j<k-1){
            curr+=nums[j];
            mp[nums[j]]++;
            j++;
        }
        
        while(j<n){
            curr+=nums[j];
            mp[nums[j]]++;
            if(j-i+1==k&&mp.size()==k){
                ans=max(ans,curr);
            }
            mp[nums[i]]--;
            curr-=nums[i];
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            i++; j++;


          
        }

        return ans;
    }
};