class Solution {
public:

    int nCr(int n, int r, int k) {
        if(r > n) return 0; 
        r = min(r, n - r); 
        long long res = 1; 
        for(int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i; 
            if(res > k) return k + 1; 
        }
        return res; 
    }

    int ways(int n, int (&f)[26], int k) {
        long long total = 1; 
        for(int i = 0;i < 26; i++) {
            total *= nCr(n, f[i], k);
            if(total > k) return k + 1; 
            n -= f[i]; 
        }
        return total; 
    }
    string smallestPalindrome(string s, int k) {
        // we only need the first half. 
        int f[26] = {0}; 
        for(char c: s) f[c-'a']++; 
        int n = s.length(); 
        string ans = s; 
        for(int i = 0; i < 26; i++) {
            if(f[i] % 2) ans[n/2] = 'a' + i; 
            f[i]/=2; 
        }

        // Now we have to put these charactres in first half. 
        int cnt = ways(n / 2, f, k); 
        if(cnt < k) return ""; 

        for(int idx = 0; idx < n / 2; idx++) {
            for(int i = 0; i < 26; i++) {
                if(f[i] == 0) continue; 
                // If we use current char at cur pos 
                f[i]--; 
                int possible = ways(n / 2 - 1 - idx, f, k); 
                if(possible >= k) {
                    ans[idx] = 'a' + i; 
                    break; 
                } else {
                    k -= possible; 
                    f[i]++; // we are not fixing this character
                }
            }
        }

        // mirror the string 
        for(int i = 0; i < n / 2; i++) ans[n - 1 - i] = ans[i]; 
        return ans; 
    }
};