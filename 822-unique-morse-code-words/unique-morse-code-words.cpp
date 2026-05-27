class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> storage = {
            ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
            "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
            "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
            "...-", ".--",  "-..-", "-.--", "--.."};

      unordered_set<string> st;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < words[i].size(); j++) {
                string ch = storage[words[i][j] - 'a'];
                temp += ch;
            }
            st.insert(temp);
        }
        return st.size();
    }
};