class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
       vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;
        
        dist[0][0]=grid[0][0];
        dq.push_front({0,0});
         int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!dq.empty()){
            auto [i,j]=dq.front();
            dq.pop_front();

            for(auto &d:dirs){
                int x=i+d[0],y=j+d[1];
                 if(x>=0 && x<m && y>=0 && y<n) {
                    int cost = dist[i][j] + grid[x][y];
                    if(cost < dist[x][y]) {
                        dist[x][y] = cost;
                        if(grid[x][y] == 0) dq.push_front({x,y});
                        else dq.push_back({x,y});
                    }
                }
            }
        }

        return dist[m-1][n-1]<health;
    }
};