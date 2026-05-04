class Solution {
public:
bool prime(int n){
    if(n==2)return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }

    return true;
}
    int largestPrime(int n) {

        long long sum = 2;
        int ans = 0;
        if (n >= 2) ans = 2;

        for (int x = 3; sum + x <= n; x++) {
            if (prime(x)) {
                sum += x;
                if (sum <= n && prime(sum)) {
                    ans = sum;
                }
            }
        }
        return ans;
    }
};