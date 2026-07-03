class Solution {
public:

 bool possible(vector<int>& q,int n,int mid){
      int cnt=0;
      for( int a:q){
         cnt+=ceil((double)a/(double)mid);

      }
return cnt<=n;
}
    int minimizedMaximum(int n, vector<int>& q) {
       int low=1;
       int high=*max_element(q.begin(),q.end());

       int ans=1;

       while(low<=high){
        int mid=(high+low)/2;
          if(possible(q,n,mid)){
            ans=mid;
            high=mid-1;
          }else{
            low=mid+1;
          }
       }
       return ans;
    }
};