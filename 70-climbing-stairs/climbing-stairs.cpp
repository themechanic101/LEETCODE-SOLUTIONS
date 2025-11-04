class Solution {
public:
int climb(int n,vector<int>&vec){
 if(n<=2) return n;
 if(vec[n]!=-1) return vec[n];
 return vec[n]=climb(n-1,vec)+climb(n-2,vec); 
}
public:
    int climbStairs(int n) {
    vector<int>vec(n+1,-1);
    int ans=climb(n,vec);
    return ans;
    }
};