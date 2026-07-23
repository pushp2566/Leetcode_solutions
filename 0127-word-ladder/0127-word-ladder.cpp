class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        int n=wordList.size();
        for(int i=0;i<n;i++){
            mp[wordList[i]]=1e9;
        }
            mp[beginWord]=1;
            queue<pair<string,int>>q;
            q.push({beginWord,1});
          //  int ans=0;
          //  
            while(!q.empty()){
                string s=q.front().first;
                int steps=q.front().second;
                q.pop();
                if(s==endWord)return steps;
                for(int i=0;i<s.size();i++){
                 char ch = s[i];
                  for(char c='a';c<='z';c++){
                       
                        if(c!=ch){
                                    s[i]=c;
                                            if(mp.find(s)!=mp.end()&&mp[s]>steps+1){
                                                q.push({s,steps+1});
                                                mp[s]=steps+1;
                                            }
                                            s[i]=ch;
                                }
                  }
                               
                                // if(c!='a'){
                                //     s[i]--;
                                //             if(mp.find(s)!=mp.end()&&mp[s]>steps+1){
                                //                 q.push({s,steps+1});
                                //                 mp[s]=steps+1;
                                //             }
                                //             s[i]++;
                                // }
                }
                         
            }


return 0;

    }
};