class Solution {
public:
    string trimTrailingVowels(string s) {
     int lastInd = s.length() - 1;
        while (lastInd >= 0) {
            char ch = s[lastInd];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                lastInd--;
            else
                break;
        }
        int lenOfAns = lastInd + 1;
        return s.substr(0, lenOfAns);
    }
};