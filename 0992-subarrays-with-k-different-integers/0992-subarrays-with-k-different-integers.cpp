class Solution {
public:
   int solve (vector<int>nums, int k){
    int n= nums.size();
    unordered_map<int,int>freq;
    int i=0,j=0;
    int ct=0;
    while(j<n&&i<n){
        freq[nums[j]]++;
        while(freq.size()>k){
            freq[nums[i]]--;
            if(freq[nums[i]]==0)freq.erase(nums[i]);
            i++;
        }
        ct+=(j-i+1);
        j++;

    }
    
return ct;


   }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return  solve(nums,k)-solve(nums,k-1);
    }
};