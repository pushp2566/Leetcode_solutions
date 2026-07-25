class Solution {
public:
    int solve(int i, map<int,vector<int>>& mp, map<int,int>& dp, int n) {
        if(i >= n) return 0;
        if(mp.find(i) == mp.end()) return dp[i] = 1e9;
        if(dp.find(i) != dp.end()) return dp[i];
        
        int x = 1e9;
        
        // Because of how we built the map, mp[i] now contains ALL taps that 
        // overlap our current position 'i'. We just try all of them.
        for(auto child : mp[i]) {
            // Only jump if the tap actually pushes us further right
            if(child > i) {
                x = min(x, 1 + solve(child, mp, dp, n));
            }
        }
 
        return dp[i] = x;
    }

    int minTaps(int n, vector<int>& ranges) {
        map<int,vector<int>> mp;
        
        for(int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]); // Clamp to 0
            int right = i + ranges[i];
            
            // KEY CHANGE: This tap can help us move forward from ANY point 
            // between 'left' and 'right'. So we add it to all of them.
            for(int j = left; j <= right; j++) {
                mp[j].push_back(right);
            }
        }
        
        map<int,int> dp;
        
        // We start exactly at 0. No need for 'mini' anymore.
        int ans = solve(0, mp, dp, n);
        
        if(ans >= 1e9) return -1;
        return ans;
    }
};