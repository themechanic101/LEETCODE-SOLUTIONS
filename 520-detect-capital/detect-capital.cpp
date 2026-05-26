class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;

      for(int i=0;i<word.size();i++){
        if(isupper(word[i])){
            cnt++;
        }
      }


      if(cnt == word.size())return true;
      else if(isupper(word[0]) && cnt==1)return true;
      else if(cnt==0)return true;
      else return false;

     
    }
};