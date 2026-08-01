class Solution {
public:
typedef long long ll;

bool valid(ll temp,vector<ll>&diff,vector<int>&m,int n){
     for(int i=0;i<n;i++){
        if(temp+diff[i]<m[i])return false;
        temp-=m[i];
        if(temp<0)temp=0;
     }

     return true;
}
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<ll>diff(n+1,0);

        for(auto t:boosts){
            int l=t[0];
            int r=t[1];
            int v=t[2];

            diff[l]+=v;
            if(r+1<n){
                diff[r+1]-=v;
                }
        }

        ll sum=monsters[0];
        for(int i=1;i<n;i++){
            sum+=monsters[i];
            diff[i]+=diff[i-1];
        }

        ll l=0;
        ll h=sum;


        while(l<=h){
            ll mid=l+(h-l)/2;

            if(valid(mid,diff,monsters,n))h=mid-1;
            else l=mid+1;

        }

        return l;

    }
};