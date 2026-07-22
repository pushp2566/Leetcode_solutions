class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n%2!=0)n--;
        long long ans;
        if(n%2!=0){
            ans= 1LL*s+ 1LL*((n/2)*m) -1LL*n/2;
        }
        else{
              ans= 1LL*s+ 1LL*(n/2)*m -1LL*(n-1)/2;
        }
return ans;
    }
};