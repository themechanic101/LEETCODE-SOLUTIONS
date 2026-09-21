class Solution {
public:
    bool checkString(string s) {
        bool fb=false;

        for(char c:s){
            if(c=='b')fb=true;
            if(fb && c=='a')return false;
        }
        return true;
    }
};