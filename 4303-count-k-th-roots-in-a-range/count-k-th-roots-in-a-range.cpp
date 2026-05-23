class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int cnt = 0;
        if(k==1)return r-l+1;
        for (long long x = 1;; x++) {
            long long y = pow(x, k); 
            if (y > r)
                break; 
            if (y >= l)
                cnt++;
        }

        if(l==0)cnt++;
    
        return cnt;
    }
};