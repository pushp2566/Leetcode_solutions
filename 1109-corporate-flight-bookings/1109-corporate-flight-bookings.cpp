class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    
        vector<int>ans(n,0);
        int m=bookings.size();
        for(int i=0;i<m;i++){
            ans[bookings[i][0]-1]+=bookings[i][2];
            if(bookings[i][1]<n){
                 ans[bookings[i][1]]+=-1*bookings[i][2];
            }
        }

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ans[i];
            ans[i]=sum;
        }

return ans;
    }
};