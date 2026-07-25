class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int upto=nums[0];
        int i=1;
        int new_upto=0;
        int ans=1;
        while(true){
              if(upto>=n-1)return ans;
              while(i<n &&i<=upto){
                new_upto=max(new_upto,i+nums[i]);
                i++;
              }
              upto=new_upto;
              ans++;
            


        }

return ans;

    }
};