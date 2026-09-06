class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int,unordered_set<int>>mp;
        mp[0].insert(0);
        int n=stones.size();
        for(int i=0;i<n;i++){
            int key=stones[i];
            for(auto x:mp[key]){
                mp[key+x].insert(x);
                mp[key+x-1].insert(x-1);
                mp[key+x+1].insert(x+1);
                
            }
        }

// if(mp.find(stones.back())==mp.end())return false;
// return true;
   return !mp[stones.back()].empty();

    }
};