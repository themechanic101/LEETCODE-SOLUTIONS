class Solution {
public:

void dfs(vector<vector<char>>& board,int row ,int col){
    if(row<0 || col<0 || row>=board.size() || col>=board[0].size())return;
    if(board[row][col]!='O')return;
    board[row][col]='V';
    dfs(board,row+1,col);
    dfs(board,row-1,col);
    dfs(board,row,col+1);
    dfs(board,row,col-1); 
}
    void solve(vector<vector<char>>& board) {
        if(board.size()==0  || board.empty())return;
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              
                if(i==0 || j==0 || i==m-1 || j==n-1  && board[i][j]=='O'){
                    dfs(board,i,j);
                }
            }
        }

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='V'){
                    board[i][j]='O';
                }
            }
        }


    }
};