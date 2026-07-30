class Solution {
public:
 bool isstars(string &S1, int i) {
    
        for (int j = 0; j <= i; j++) {
            if (S1[j] != '*')
                return false;
        }
        return true;
    }

bool  solve(string &s,string &p,int i,int j, vector<vector<int>>&dp){
    if(i<0 && j<0)return true;

    if(j<0 && i>=0)return false;

    if(j>=0 && i<0)return isstars(p,j);

    if(dp[i][j]!=-1)return dp[i][j];

    if(s[i]==p[j] || p[j]=='?')return dp[i][j]=solve(s,p,i-1,j-1,dp);

    if(p[j]=='*')return dp[i][j]=solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp);

    return dp[i][j]=false;


    

} 
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(s,p,m-1,n-1,dp);
    }
};