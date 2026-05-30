class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int> ans(s.size(), 1e9);

        int seen = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c){
                ans[i] = 0;
                seen=i;
            }

            if (s[i] != c && seen != -1)
                ans[i] = min(abs(seen - i),ans[i]);
        }

        seen = -1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c){
                ans[i] = 0;
                seen=i;
            }

            if (s[i] != c && seen != -1)
                ans[i] = min(abs(seen - i), ans[i]);
        }

        return ans;
    }
};