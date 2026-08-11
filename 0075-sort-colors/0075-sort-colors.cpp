class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            int midd=nums[mid];
            if(midd==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(midd==1){
              mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};