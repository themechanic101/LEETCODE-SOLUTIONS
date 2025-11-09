class Solution {
public:
void combination(string digits,vector<string>&ans,int index,string curr, unordered_map<char,string>mp){
    if(index>=digits.size()){
        ans.push_back(curr);
        return;
    }
    char ch=digits[index];
    string str=mp[ch];
    for(int i=0;i<str.size();i++){
       curr.push_back(str[i]);
       combination(digits,ans,index+1,curr,mp);
       curr.pop_back();
    }
}
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
      unordered_map<char,string>mp;
      mp['2']="abc";
      mp['3']="def";
    mp['4']="ghi";
     mp['5']="jkl";
     mp['6']="mno";
     mp['7']="pqrs";
    mp['8']="tuv";
       mp['9']="wxyz";
          string curr="";
          if(digits.size()==0)return {};
          combination(digits,ans,0,curr,mp);
          return ans;
    }
};