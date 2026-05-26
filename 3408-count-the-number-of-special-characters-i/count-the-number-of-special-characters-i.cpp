class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt=0;
        for(char ch='a';ch<='z';ch++){
            if(word.find(ch)!=-1 && word.find(ch-32)!=-1) cnt++;
        }
        return cnt;
        
    }
};