class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=k;
 vector<int> v(26, 0);
        int i=0,j=0;
        while(j<n){
            
           v[s[j]-'A']++;
                        int max_ind=0;
                        int maxi=-1;
                        int tot=0;
                        for(int k=0;k<26;k++){
                            if(v[k]>=maxi){
                                maxi=v[k];
                                max_ind=k;
                                
                            }
                            tot+=v[k];
                        }
 
int rem=tot-maxi;

while(i <= j && rem > k){
  v[s[i] - 'A']--;
    i++;

int max_ind2=0;
                        int maxi2=-1;
                        int tot2=0;
                        for(int k=0;k<26;k++){
                            if(v[k]>=maxi2){
                                maxi2=v[k];
                                max_ind2=k;
                                
                            }
                            tot2+=v[k];
                        }

rem= tot2-maxi2;

}

ans=max(ans,j-i+1);
 j++;
        }


        return ans;
    }
};