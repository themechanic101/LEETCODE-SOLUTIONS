class Solution {
public:
bool check(string s){
    int l=0,r=s.size()-1;

    while(l<=r){
        if(s[l]!=s[r])return false;
        l++;
        r--;
    }
    return true;
}
    bool isPalindromic(string s) {
        string t;
        for(char c:s){
            int ch=int(c);
            bitset<8>b(ch);
           t+= b.to_string();
            
        }
        return check(t);
    }
};