class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1)return s;
        int n =s.size();

        vector<int>mp(26,0);
        string ans(n,' ');

        for(char c:s)mp[c-'a']++;
        int l=0,r=n-1;

        for(int i=0;i<26;i++){
           while(mp[i]>=2){
            ans[l++]='a'+i;
            ans[r--]='a'+i;
            mp[i]-=2;
           }

           if(mp[i]==1){
            ans[s.size()/2]='a'+i;
           }
        }

        return ans;
    }
};