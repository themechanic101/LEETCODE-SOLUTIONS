class Solution {
public:
    int countRotations(string s, int k) {
        string s1=s+s;
        int n=s.size();
      int score=0;

      for(int j=0;j<n-1;j++){
        if(s1[j]==s1[j+1]){
            score++;
        }
      }

      int ans=0;
      if(score==k)ans++;

      for(int i=0;i<n-1;i++){
        if(s1[i]==s1[i+1])score--;

        if(s1[i+n-1]==s1[i+n])score++;

        if(score==k)ans++;
      }
      return ans;
    }
};