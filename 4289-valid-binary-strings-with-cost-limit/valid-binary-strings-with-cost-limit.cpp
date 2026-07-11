class Solution {
public:
void solve(vector<string>&ans,int idx,string &curr,int n,int k,bool seen,int cost){

    if(cost>k)return;


    if(idx==n){
        ans.push_back(curr);
        return ;
    }

    curr+='0';
     solve(ans,idx+1,curr,n,k,false,cost);
     curr.pop_back();


    if(!seen){
        curr+='1';
        solve(ans,idx+1,curr,n,k,true,cost+idx);
        curr.pop_back();
    }


}
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        string curr="";

        solve(ans,0,curr,n,k,false,0);
        return ans;
    }
};