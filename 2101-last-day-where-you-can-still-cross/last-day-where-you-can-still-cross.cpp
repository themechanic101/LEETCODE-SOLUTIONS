class Solution {
public:
    int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
        vector<vector<int>>df(m,vector<int>(n,0));
         vector<vector<int>>dist(m,vector<int>(n,0));

        for(int i=0;i<cells.size();i++){
            
           
                df[cells[i][0]-1][cells[i][1]-1]=i+1;
            
        }

      
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>>pq;
        for(int i=0;i<n;i++){
             int d=df[0][i];
             dist[0][i]=d;
             pq.push({d,0,i});
        }
        vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};

while (!pq.empty()) {
    auto [d, r, c] = pq.top();
    pq.pop();

    if (r == m - 1) {
        return d - 1;
    }


    if (d < dist[r][c]) continue;


    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

    
        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
           
            int next_d = min(d, df[nr][nc]);

            
            if (next_d > dist[nr][nc]) {
               dist[nr][nc] = next_d;
                pq.push({next_d, nr, nc});
            }
        }
    }
}

return 0;
        
    }
};