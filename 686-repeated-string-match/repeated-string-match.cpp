typedef long long ll;
class Solution {
public:

 int rabinkarp(string& s, string& t) 
    {
        ll p = 31, m = 1e9 + 9;
        int S = s.size(), T = t.size();
        
        vector<ll> power(max(S, T), 1);
        for(int i = 1; i < power.size(); i++)
            power[i] = (power[i-1]*p) % m;

        vector<ll> H(T + 1, 0);
        for(int i = 0; i < T; i++)
            H[i+1] = (H[i] + (t[i]-'a'+1)*power[i])%m;
        
        ll HS = 0;
        for(int i = 0; i < S; i++)
            HS = (HS + (s[i]-'a'+ 1)*power[i])%m;
        
        ll currHS = 0;
        for(int i = 0; i + S <= T; i++)
        {
            currHS = (H[i + S] - H[i] + m) % m;
            if(currHS == HS*power[i]%m)
                return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        string source=a;
        int cnt=1;

        while(source.size()<b.size()){
            cnt++;
            source+=a;
        }
        if(source==b)return cnt;

        if(rabinkarp(b,source))return cnt;

        source+=a;

if(rabinkarp(b,source))return cnt+1;

return -1;
    }
};