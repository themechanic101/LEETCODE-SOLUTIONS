class Solution {
public:
static bool comp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& inv) {
        int n=inv.size();

        sort(inv.begin(),inv.end(),comp);

        int cnt=1,lastendtime=inv[0][1];

        for(int i=1;i<n;i++){
            if(inv[i][0]>=lastendtime){
                
            lastendtime=inv[i][1];
            cnt++;
            }
        }

        return n-cnt;
    }
};