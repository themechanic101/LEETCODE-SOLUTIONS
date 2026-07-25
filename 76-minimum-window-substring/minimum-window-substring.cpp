class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;

        for(int i=0;i<t.size();i++)mp[t[i]]++;

        int cnt=0;
        int minlen=INT_MAX;
        int l=0,r=0,sindex=-1;
        

        while(r<s.size()){
            if(mp[s[r]]>0)cnt++;
            mp[s[r]]--;

            while(cnt==t.size()){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }
                

                mp[s[l]]++;
                if(mp[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }

        return sindex==-1?"":s.substr(sindex,minlen);
    }
};