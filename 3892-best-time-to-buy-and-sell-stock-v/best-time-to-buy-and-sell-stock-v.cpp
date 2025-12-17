class Solution {
    //buy>>>sell CASE 1
    //shortsell>>>buy CASE 2
    //buy and shortsell (for fresh transaction)  CASE 0
public:
long long t[1001][501][3];

long long solve(vector<int>&prices,int k,int CASE,int index){
     if(index== prices.size()){
        if(CASE==0)return 0;
        return INT_MIN;
     }
     if(t[index][k][CASE]!=INT_MIN)return t[index][k][CASE];

     long long take=INT_MIN;
     long long donttake;

     donttake=solve(prices,k,CASE,index+1);

     if(k>0){
        if(CASE==1){
            //sell today (complete normal transaction)
            take=prices[index]+solve(prices,k-1,0,index+1);
        }else if(CASE==2){
            take= -prices[index]+solve(prices,k-1,0,index+1);
        }else{
            take=max(prices[index]+solve(prices,k,2,index+1),//short sell 
            -prices[index]+solve(prices,k,1,index+1));//normal sell
        }
     }

    return t[index][k][CASE]=max(take,donttake);
}
long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        for(int i=0;i<1001;i++){
            for(int j=0;j<=k;j++){
                for(int l=0;l<3;l++){
                    t[i][j][l]=INT_MIN;
                }
            }
        }
        return solve(prices,k,0,0);
    }
};