class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l=0;
       int r=s.size()+1;
       int n=r;
        vector<int>ans(r);

        for(int i=0;i<=s.size();i++){
            if(s[i]=='I'){
                ans[i]=l;
                l++;
            }else if(s[i]=='D'){
                ans[i]=r-1;
                r--;
            }
        }
ans[n-1]=r-1;
        return ans;
    }
};