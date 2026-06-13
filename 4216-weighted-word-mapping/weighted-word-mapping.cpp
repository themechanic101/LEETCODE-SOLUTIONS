class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto word:words){
            int sum=0;
            for(auto c:word){
                sum+=weights[c-'a'];
                sum%=26;
            }
            ans.push_back('z'-sum);
        }
        return ans;
    }
};