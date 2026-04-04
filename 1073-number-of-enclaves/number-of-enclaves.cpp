class Solution {
public:
void dfs(vector<vector<int>>& grid,int row,int col){
    if(row<0 || col <0 || row >=grid.size() || col >=grid[0].size() || grid[row][col]==0)return;
    if(grid[row][col]==2)return;
    grid[row][col]=2;
    dfs(grid,row+1,col);
    dfs(grid,row-1,col);
    dfs(grid,row,col+1);
    dfs(grid,row,col-1);
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int cnt=0;
        

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1 && grid[i][j]==1){
                    dfs(grid,i,j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==1)cnt++;
            }
        }


        return cnt;

    }
};