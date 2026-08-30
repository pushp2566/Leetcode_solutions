class Solution {
public:
    int minAddToMakeValid(string s) {
        int ct=0;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ct++;
            }
            else{
                ct--;

                if(ct<0){
                    ct++;ans++;
                }
            }
        }

        ans+=ct;
        return ans;

    }
};