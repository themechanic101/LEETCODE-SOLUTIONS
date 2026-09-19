typedef long long ll;
class Solution {
public:
typedef long long ll;
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        
        priority_queue<tuple<ll ,int,int,int>,vector<tuple<ll,int,int,int>>,greater<tuple<ll,int,int,int>>>pq;
        vector<vector<vector<ll>>>dist(m,vector<vector<ll>>(n,vector<ll>(2,LLONG_MAX)));
        //dist[r][c][parity]

        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        //{cost,r,c,parity}

        dist[0][0][1]=1;
        pq.push({1,0,0,1});
        while(!pq.empty()){
           auto[cost,r,c,par]=pq.top();
           pq.pop();

           if(cost>dist[r][c][par])continue;
           if(r==m-1 && c==n-1)return cost;
           //wait
           int np=par^1;

           if(cost+penalty[r][c]<dist[r][c][np]){
            dist[r][c][np]=cost+penalty[r][c];
            pq.push({dist[r][c][np],r,c,np});
           }

           //4 direct
           for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=m || nr<0 || nc>=n || nc<0)continue;

            int encost=(nr+1)*(nc+1);
            bool violation=false;
            
            if(par==1){
                if(nc<c || nr<r)violation=true;
            }else{
                if(nc>c || nr>r)violation=true;
            }
            ll total=cost+encost+(violation?penalty[r][c]:0);
            if(total<dist[nr][nc][np]){
                dist[nr][nc][np]=total;
            pq.push({total,nr,nc,np});
            }
           }
        }
        return -1;
    }
};