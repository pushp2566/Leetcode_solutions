class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0,j=2;
        while(i<n&&j<n){
            while(j-i<2)j++;
            int diff1=nums[i+1]-nums[i];
            int diff2=nums[j]-nums[j-1];
            if(diff1!=diff2){
                i=j-1;
            }
            else{
             ans+=(j-i-1);
             j++;
            }

        }

        return ans;
    }
};