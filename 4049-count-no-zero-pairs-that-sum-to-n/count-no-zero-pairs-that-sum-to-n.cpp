class Solution {
public:
typedef long long ll;

ll dp[16][2][2][2];
string s;
long long solve(int idx,bool endA,bool endB,int carry) {
    if(idx<0){
        return carry == 0;
    }

     if (dp[idx][endA][endB][carry] != -1){
            return dp[idx][endA][endB][carry];
        }


    int uba=endA?0:9;
    int ubb=endB?0:9;
    int lb=(idx==s.size()-1)?1:0;

    ll ans=0;

    for(int a=lb;a<=uba;a++){
        for(int b=lb;b<=ubb;b++){
            int sum=a+b+carry;
            if(sum%10==s[idx]-'0'){
                ans+=solve(idx-1,endA | a==0,endB | b==0,sum/10);
            }
        }
    }
    return dp[idx][endA][endB][carry]=ans;
}
    long long countNoZeroPairs(long long n) {
        memset(dp,-1,sizeof(dp));
        s=to_string(n);
       return solve(s.size()-1,false,false,0);
    }
};