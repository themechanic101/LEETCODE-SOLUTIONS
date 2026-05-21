class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int cnt = 0;
        unordered_set<int> prefixes;
        for (int num : arr1) {
            string s = to_string(num);
            string prefix = "";
            for (char c : s) {
                prefix += c;
                prefixes.insert(stoi(prefix));
            }
        }

        for (int num : arr2) {
            string s = to_string(num);
            string prefix = "";
            for (char c : s) {
                prefix += c;
                int val = stoi(prefix);
                if (prefixes.find(val) != prefixes.end()) {
                    int temp=prefix.size();
                    cnt = max(cnt, temp);
                }
            }
        }

        return cnt;
    }
};