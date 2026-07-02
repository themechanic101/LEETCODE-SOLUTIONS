class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto[i,j]=q.front();
            q.pop();

            for(auto d:dir){
                int x=i+d[0],y=j+d[1];
                if(x>=0 && x<m && y>=0 && y<n){
                     int cost = dp[i][j] + grid[x][y];
                    if(cost < dp[x][y]) {
                        dp[x][y] = cost;
                        q.push({x,y});
                    }
                }
            }
        }

        return dp[m-1][n-1]<health;
    }
};