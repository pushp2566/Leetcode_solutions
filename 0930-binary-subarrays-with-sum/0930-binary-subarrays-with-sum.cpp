





class Solution {
public:
    int solve(vector<int>&nums,int k){
         int n=nums.size();
        int i=0,j=0;
        int ct=0;
        int ans=0;
        while(j<n){
            ct+=nums[j];
            while(i<n&&ct>k){
                ct-=nums[i];
                i++;
            }
            ans+=max(0,j-i+1);
            j++;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)nums[i]=0;
            else nums[i]=1;
        }

        return solve(nums,k)-solve(nums,k-1);
    }
};