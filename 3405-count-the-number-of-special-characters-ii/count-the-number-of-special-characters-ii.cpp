class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        unordered_set<char> small, big;
        vector<int> ans(26, 0);
        int res = 0;

        for(int i=0; i<n; i++){
            char ch = word[i];

            if(ch >= 'a' && ch <= 'z'){
                if(big.count(ch-'a'+'A')>0 ) ans[ch-'a'] = -1;
                small.insert(ch);
            }
            else {
                if(small.count(ch-'A'+'a')>0){
                    if(ans[ch-'A'] != -1) ans[ch-'A'] = 1;
                }
                big.insert(ch);
            }
        }

        for(int i=0; i<26; i++){
            
            if(ans[i] <= 0) continue;
            res += ans[i];
        }

        return res;
    }
};