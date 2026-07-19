class Solution {
public:
    string smallestSubsequence(string s) {
       vector<int>last(26);

       for(int i=0;i<s.size();i++){
        last[s[i]-'a']=i;
       }

       vector<bool>instack(26,false);

       stack<char>st;


       for(int i=0;i<s.size();i++){
        char ch=s[i];

        if(instack[ch-'a'])continue;

        while(!st.empty() && st.top()>ch && last[st.top()-'a']>i ){
            instack[st.top()-'a']=false;
            st.pop();
        }

        st.push(ch);
        instack[ch-'a']=true;
       }
       string ans="";


       while(!st.empty()){
           char ch=st.top();
           ans+=ch;
           st.pop();
       }
reverse(ans.begin(),ans.end());
       return ans;
    }
};