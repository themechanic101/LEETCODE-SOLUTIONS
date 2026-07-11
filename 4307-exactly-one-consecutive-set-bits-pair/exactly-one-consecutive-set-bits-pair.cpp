class Solution {
public:
    bool consecutiveSetBits(int n) {
        bitset<32>b(n);

        string s=b.to_string();
        int cnt=0;

        int len=s.size();
        for(int i=len-1;i>0;i--){
            if(s[i-1]=='1' && s[i]=='1' )cnt++;
            if(cnt>1)return false;
        }

        return cnt==1;
    }
};