class Solution {
    //buy>>>sell CASE 1
    //shortsell>>>buy CASE 2
    //buy and shortsell (for fresh transaction)  CASE 0
public:
// long long t[1001][501][3];

// long long solve(vector<int>&prices,int k,int CASE,int index){
//      if(index== prices.size()){
//         if(CASE==0)return 0;
//         return INT_MIN;
//      }
//      if(t[index][k][CASE]!=INT_MIN)return t[index][k][CASE];

//      long long take=INT_MIN;
//      long long donttake;

//      donttake=solve(prices,k,CASE,index+1);

//      if(k>0){
//         if(CASE==1){
//             //sell today (complete normal transaction)
//             take=prices[index]+solve(prices,k-1,0,index+1);
//         }else if(CASE==2){
//             take= -prices[index]+solve(prices,k-1,0,index+1);
//         }else{
//             take=max(prices[index]+solve(prices,k,2,index+1),//short sell 
//             -prices[index]+solve(prices,k,1,index+1));//normal sell
//         }
//      }

//     return t[index][k][CASE]=max(take,donttake);
// }
  //      return solve(prices,k,0,0);

long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        long long t[1001][501][3];
        //base case
        for(int i=0;i<=k;i++){
            t[n][i][0]=0;
            t[n][i][1]=INT_MIN;
            t[n][i][2]=INT_MIN;
        }
        for(int i=n-1;i>=0;i--){
            for(int l=0;l<=k;l++){
                t[i][l][0]=t[i+1][l][0];//donttake

                if(l>0){
                    t[i][l][0]=max(t[i][l][0],
                    max(-prices[i]+t[i+1][l][1],prices[i]+t[i+1][l][2]));
                }
                t[i][l][1]=t[i+1][l][1];//hold
                 if(l>0){
                    t[i][l][1]=max(t[i][l][1],
                    prices[i]+t[i+1][l-1][0]);
                }

                t[i][l][2]=t[i+1][l][2];
                 if(l>0){
                    t[i][l][2]=max(t[i][l][2],
                    -prices[i]+t[i+1][l-1][0]);
                }



            }
        }
        return t[0][k][0];
    }
};