class Solution {
public:
    int minimumPushes(string w) {
        int n=w.size();
        int cnt=0;

       if(n<=8)return n;
       else {
        int i=1;
        while(n>8){
            cnt+=8*i;
            i++;
            n-=8;
        }

        cnt+=n*i;
       }

       return cnt;
      
    }
};