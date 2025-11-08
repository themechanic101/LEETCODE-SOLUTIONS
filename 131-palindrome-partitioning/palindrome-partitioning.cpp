class Solution {
public:
bool check(string& s , int left ,int right) {
   
    while (left < right) {
        if (s[left] != s[right])
            return false;
        ++left;
        --right;
    }
    return true;
}
void partition(vector<vector<string>>&ans,string s,int left,vector<string>&vec){
  if(left==s.size()){
    ans.push_back(vec);
    return;
  }

  for(int right=left;right<s.size();right++){
    if(check(s,left,right)){
        vec.push_back(s.substr(left,right-left+1));
        partition(ans,s,right+1,vec);
        vec.pop_back();
    }
  }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>vec; 
        partition(ans,s,0,vec);
        return ans;
    }
};