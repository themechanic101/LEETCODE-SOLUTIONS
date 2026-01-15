class Solution {
public:
void solve(vector<vector<char>>& grid,int x,int y,int m,int n){
  if(x<0 || y<0 || x>=m || y>=n)return ;

  if(grid[x][y] != '1')return ;

grid[x][y]='0';
  solve(grid,x,y+1,m,n);
  solve(grid,x,y-1,m,n);
  solve(grid,x+1,y,m,n);
  solve(grid,x-1,y,m,n);

}
    int numIslands(vector<vector<char>>& grid) {
    int m=grid.size();
    int n=grid[0].size();

    int cnt=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                cnt++;
                solve(grid,i,j,m,n);
            }
        }
    }

    return cnt;
    }
};