class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> ans;
        for(int i=0;i<letters.size();i++){
            int val=letters[i]-'a';
            ans.push_back(val);
        }
        int pos=target-'a';
        for(int i=0;i<ans.size();i++){
            if(ans[i]>pos) return ans[i]+'a';
        }
        return letters[0];
        
    }
};