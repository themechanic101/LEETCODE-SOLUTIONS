class Solution {
public:
const long long M=1e9+7;
    int concatenatedBinary(int n) {
        long ans=0;
        for(int num=1;num<=n;num++){
            int digit=log2(num)+1;
            ans=((ans << digit)%M+num)%M;
        }

        return ans;
    }
};