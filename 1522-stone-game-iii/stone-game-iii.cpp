class Solution {
public:

int solve(int i,vector<int>& s, vector<int>&dp){
    if(i>=s.size())return 0;

    if(dp[i]!=1e9)return dp[i];

    int ans=s[i]+min(solve(i+2,s,dp),min(solve(i+3,s,dp),solve(i+4,s,dp)));

    if(i+1<s.size()){
       int op2=s[i]+s[i+1]+min(solve(i+3,s,dp),min(solve(i+4,s,dp),solve(i+5,s,dp)));
       ans=max(ans,op2);
    }
     if(i+2<s.size()){
       int op3=s[i]+s[i+1]+s[i+2]+min(solve(i+4,s,dp),min(solve(i+5,s,dp),solve(i+6,s,dp)));
       ans=max(ans,op3);
    }

    return dp[i]=ans;
}
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        int total=accumulate(stoneValue.begin(),stoneValue.end(),0);
        vector<int>dp(n,1e9);

        int ans=solve(0,stoneValue,dp);

        if(total%2==0 && total/2==ans)return "Tie";
        else if(total-ans<ans)return "Alice";
        return "Bob";
    }
};