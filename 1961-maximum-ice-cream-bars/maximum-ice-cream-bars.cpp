class Solution {
public:
    int maxIceCream(vector<int>& c, int coins) {
        sort(c.begin(),c.end());
        int cnt=0;

        for(int i=0;i<c.size();i++){
            if(c[i]<=coins){
                coins-=c[i];
                cnt++;
            }
        }

        return cnt;
    }
};