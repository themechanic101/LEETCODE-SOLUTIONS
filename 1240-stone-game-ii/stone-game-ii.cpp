class Solution {
public:
//rules in game theory 
//1>> do wahtever you can for your best outcomes
//2>> expect the worst outcome for you from your opponent


int solve(vector<int>& piles,vector<vector<vector<int>>>&dp,int m,int idx ,int turn){
    if(idx>=piles.size())return 0;
     if (dp[m][idx][turn] != -1) return dp[m][idx][turn];

    int stonecnt=0;
    int ans=(turn==0)?0:INT_MAX;


    for(int x=1;x<=(2*m);x++){
        int pileidx=idx+x-1;
        if(pileidx>=piles.size())break;
        stonecnt+=piles[pileidx];

        if(turn==0){
           int nextcnt=solve(piles,dp,max(m,x),pileidx+1,1);
           int total=stonecnt+nextcnt;
           ans=max(ans,total);
        }else{
            int nextcnt=solve(piles,dp,max(m,x),pileidx+1,0);
        
            ans=min(ans,nextcnt);
        }

        
    }
    return dp[m][idx][turn]=ans;
}


    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
         vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(piles,dp,1,0,0);
    }
};