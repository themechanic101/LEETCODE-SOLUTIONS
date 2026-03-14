class Solution {
public:
void solve(int n,string curr, vector<string>&ans){
   if(curr.size()==n){
    ans.push_back(curr);
    return;
   }


   for(char ch='a';ch<='c';ch++){
    if(!curr.empty() && curr.back()==ch)continue;
        curr+=ch;
    
    solve(n,curr,ans);

    curr.pop_back();
   }


}
    string getHappyString(int n, int k) {
        string curr="";

        vector<string>ans;

        solve( n,curr,ans);
        if(k>ans.size())return "";

        return ans[k-1];
    }
};