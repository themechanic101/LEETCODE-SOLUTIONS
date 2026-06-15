class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;

        int cnt=0;
        for(char c:s){
            if(c=='L')cnt--;
            if(c== 'R') cnt++;

            if(cnt==0)ans++;
        }

        return ans;
    }
};