class Solution {
public:
void adjacent(int n ,vector<string>&ans,int ind,string curr_str){
    if(ind==n){
        ans.push_back(curr_str);
        return;
    }
    if(curr_str.empty()  || curr_str.back()!='0'){
       curr_str+="0";
    adjacent(n,ans,ind+1,curr_str);
    curr_str.pop_back();
    }

    
    curr_str+="1";
    adjacent(n,ans,ind+1,curr_str);
    curr_str.pop_back();
}         
public:
    vector<string> validStrings(int n) {
        vector<string>ans;
        string curr_str="";
        adjacent(n,ans,0,curr_str);
        return ans;
    }
};