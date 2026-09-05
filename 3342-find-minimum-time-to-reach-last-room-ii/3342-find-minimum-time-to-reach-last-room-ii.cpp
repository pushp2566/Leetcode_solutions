class Solution {
public:
    bool valid(int n, int m, int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    long long minTimeToReach(vector<vector<int>>& moveTime) {

        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<vector<long long>>> time(
            n,
            vector<vector<long long>>(m, vector<long long>(3, 1e18))
        );

        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > pq;

        time[0][0][1] = 0;

        // {time, current_move_time, i, j}
        pq.push({0, 1, 0, 0});

        while(!pq.empty()) {

            vector<long long> temp = pq.top();
            pq.pop();

            long long t = temp[0];
            long long curr = temp[1];
            int i = temp[2];
            int j = temp[3];

            long long next = 1;
            if(curr == 1)
                next = 2;

            if(i == n-1 && j == m-1)
                return t;

            if(valid(n,m,i+1,j) &&
               time[i+1][j][next] >
               max((long long)moveTime[i+1][j], time[i][j][curr]) + curr) {

                long long tt =
                    max((long long)moveTime[i+1][j], time[i][j][curr]) + curr;

                time[i+1][j][next] = tt;
                pq.push({tt,next,i+1,j});
            }

            if(valid(n,m,i-1,j) &&
               time[i-1][j][next] >
               max((long long)moveTime[i-1][j], time[i][j][curr]) + curr) {

                long long tt =
                    max((long long)moveTime[i-1][j], time[i][j][curr]) + curr;

                time[i-1][j][next] = tt;
                pq.push({tt,next,i-1,j});
            }

            if(valid(n,m,i,j+1) &&
               time[i][j+1][next] >
               max((long long)moveTime[i][j+1], time[i][j][curr]) + curr) {

                long long tt =
                    max((long long)moveTime[i][j+1], time[i][j][curr]) + curr;

                time[i][j+1][next] = tt;
                pq.push({tt,next,i,j+1});
            }

            if(valid(n,m,i,j-1) &&
               time[i][j-1][next] >
               max((long long)moveTime[i][j-1], time[i][j][curr]) + curr) {

                long long tt =
                    max((long long)moveTime[i][j-1], time[i][j][curr]) + curr;

                time[i][j-1][next] = tt;
                pq.push({tt,next,i,j-1});
            }
        }

        return -1;
    }
};