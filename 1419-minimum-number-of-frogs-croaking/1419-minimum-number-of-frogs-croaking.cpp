class Solution {
public:
    int minNumberOfFrogs(string s) {
       int n= s.size();
       int ans=0;
       int ct=0;
         map<char,int>mp;
       mp['c']=0;
        mp['r']=0;
         mp['o']=0;
          mp['a']=0;
           mp['k']=0;
     
                for(int i=0;i<n;i++){
                    mp[s[i]]++;
                    if(s[i]=='k'){
                        ct--;
                        if(mp['a']<mp[s[i]]||mp['o']<mp[s[i]]||mp['r']<mp[s[i]]||mp['c']<mp[s[i]])return -1;
                    }
                     if(s[i]=='a'){
                      //  ct--;
                        if(mp['o']<mp[s[i]]||mp['r']<mp[s[i]]||mp['c']<mp[s[i]])return -1;
                    }
                     if(s[i]=='o'){
                       // ct--;
                        if(mp['r']<mp[s[i]]||mp['c']<mp[s[i]])return -1;
                    }
                     if(s[i]=='r'){
                       // ct--;
                        if(mp['c']<mp[s[i]])return -1;
                    }
                     if(s[i]=='c'){
                       ct++;
                       ans=max(ans,ct);
                    }
                    
                }
                int x=mp['c'];
                if(x!=mp['r']||x!=mp['o']||x!=mp['a']||x!=mp['k'])return -1;
       return ans;
        
    }
};