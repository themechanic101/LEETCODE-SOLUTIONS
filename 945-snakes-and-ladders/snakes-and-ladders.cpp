class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
     int n=board.size();
     vector<int>rolls(n*n+1,-1);

     queue<int>q;
      rolls[1]=0;
     q.push(1);
     while(!q.empty()){
        int vb=q.front();
        q.pop();
        for(int i=1;i<=6 && vb+i<=n*n ;i++){
            int t=vb+i;
            int row=(t-1)/n;
            int col=(t-1)%n;
            int bv= board[n-1-row][row%2 ? n-1-col : col];
            int k=bv>0?bv:t;
            if(k==n*n)return rolls[vb]+1;

            if(rolls[k]==-1){
                rolls[k]=rolls[vb]+1;
                q.push(k);
            }
        }
     }
     return -1;
    }
};