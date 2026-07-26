class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      unordered_map<char,int>mp;

      for(char ch:tasks)mp[ch]++;

      int maxf=0;
      for(auto &t:mp){
        maxf=max(maxf,t.second);
      }

      int cntmax=0;

      for(auto it :mp){
        if(it.second==maxf)cntmax++;
      }


      int ans=(maxf-1)*(n+1)+cntmax;

      ans=max((int)tasks.size(),ans);

      return ans;
    }
};