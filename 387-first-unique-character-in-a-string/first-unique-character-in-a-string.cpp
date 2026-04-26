class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        int ans = -1;

        for (auto ch : s) {
            mp[ch]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == 1) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};