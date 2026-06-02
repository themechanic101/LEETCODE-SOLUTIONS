class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> hash(128, 0); 

        for (char c : s) {
            hash[c]++;
        }

        int ans = 0;
        bool hasodd = false;

       for( auto cnt :hash){
        ans+=(cnt/2)*2;
        if(cnt%2==1)hasodd=true;
       }


       if(hasodd)ans++;

        return ans;
    }
};