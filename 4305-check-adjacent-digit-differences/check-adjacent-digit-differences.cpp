class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            ans.push_back(s[i]-'0');
        }
        for(int i=0;i<ans.size()-1;i++){
            if(abs(ans[i]-ans[i+1])>2) return false;
        }
        return true;
        
        
    }
};