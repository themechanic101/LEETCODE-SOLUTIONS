class Solution {
public:
unordered_set<string>st;
bool word(string &s,int index,vector<int>&dp){
      if(index==s.size())return true;
      if(dp[index]!=-1) return dp[index];

    //   if(st.find(s)!=st.end())return dp[index]= true;

      for(int i=1;i<=s.size();i++){
          string curr=s.substr(index,i);
          if(st.find(curr)!=st.end() && word(s,index+i,dp))return dp[index]= true;
      }
      return dp[index]=false;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(300,-1);
        for(string &str: wordDict){
            st.insert(str);
        }

      return word(s,0,dp);
    }
};