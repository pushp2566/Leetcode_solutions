class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int opt1=0,opt2=1,ct1=0,ct2=0;
     for(int i=0;i<n;i++){
        if(nums[i]==opt1){
            ct1++;
        }
        else if(nums[i]==opt2){
            ct2++;
        }
        else if(ct1==0){
            ct1=1;opt1=nums[i];
        }
        else if(ct2==0){
            ct2=1;opt2=nums[i];
        }
        else{
            ct1--;ct2--;
        }

     }

     ct1=0,ct2=0;
     for(int i=0;i<n;i++){
if(nums[i]==opt1)ct1++;
if(nums[i]==opt2)ct2++;
     }

vector<int>ans;
if(ct1>(n/3))ans.push_back(opt1);
if(ct2>(n/3))ans.push_back(opt2);


return ans;

    }
};