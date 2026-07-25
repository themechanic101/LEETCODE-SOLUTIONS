class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>a;
        stack<char>b;
        for(char ch:s){
            if(ch=='#'){
               if(!a.empty()){
                   a.pop();
               }
            }
            else a.push(ch);
        }
        for(char ch:t){
            if(ch=='#'){
               if(!b.empty()){
                   b.pop();
               }
            }
            else b.push(ch);
        }
        return a==b;     
    }
};