class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int curr=1;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            curr=curr*nums[j];
            while(i<=j&&curr>=k){
                curr=curr/nums[i];
                i++;
            }
             
           if(curr<k) ans+=(j-i+1);
            j++;
        }

        return ans;
    }
};