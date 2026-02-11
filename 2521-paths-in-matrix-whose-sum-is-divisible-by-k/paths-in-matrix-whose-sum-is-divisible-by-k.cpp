class Solution {
public:
int m,n;
vector<vector<vector<int>>>dp;
int M=1e9 + 7;

int solve(int i,int j ,int currsum,int k,vector<vector<int>>& grid){
    if(i>=m || j>=n)return 0;

    if(i==m-1  && j==n-1){
        return((currsum +grid[i][j])%k==0) ;
    }

    if(dp[i][j][currsum]!=-1)return dp[i][j][currsum];
   int down =solve(i+1,j,(currsum+grid[i][j])%k,k,grid);
   int right=solve(i,j+1,(currsum+grid[i][j])%k,k,grid);

 return dp[i][j][currsum]=(down +right)%M;
}

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
dp.assign(m,vector<vector<int>>(n,vector<int>(k,-1)));
         return solve(0,0,0,k,grid);
    }
};