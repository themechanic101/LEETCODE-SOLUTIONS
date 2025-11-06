class Solution {
public:
void combination(int start,vector<int>&comb,vector<vector<int>>&ans,int n,int k){
    if(comb.size()==k){
        ans.push_back(comb);
        return;
    }

    for(int num=start;num<=n;num++){
        comb.push_back(num);
        combination(num+1,comb,ans,n,k);
        comb.pop_back();
    }
}


public:
    vector<vector<int>> combine(int n, int k) {
     vector<vector<int>>ans;
     vector<int>comb;
     combination(1,comb,ans,n,k);
     return ans;   
    }
};