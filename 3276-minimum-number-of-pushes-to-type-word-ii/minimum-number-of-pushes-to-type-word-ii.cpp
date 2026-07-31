class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);

        for( char c:word)mp[c-'a']++;

        sort(mp.rbegin(),mp.rend());

        int cnt=0;

        for(int i=0;i<26;i++){
            if(mp[i]!=0){
                cnt+=(i/8+1)*mp[i];
            }
        }

        return cnt;
        
    }
};