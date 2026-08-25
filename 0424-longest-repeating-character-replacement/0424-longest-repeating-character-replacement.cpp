class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int n=s.size();
int i=0;
int maxi=0;
int res=0;
for(int j=0;j<n;j++){
    freq[s[j]-'A']++;
maxi=max(maxi,freq[s[j]-'A']);

int rem=j-i+1-(maxi);
while(rem>k){
freq[s[i]-'A']--;
    i++;
    rem=j-i+1-(maxi);
            maxi=0;
            for(int x=0;x<26;x++){
                maxi=max(maxi,freq[x]);
            }
}


    res=max(res,j-i+1);







}


return res;
    }
};
