class Solution {
public:
    bool stoneGame(vector<int>& p) {
        int n = p.size();
        int a=0;
        int l=0,r=n-1;

        int sum=accumulate(p.begin(),p.end(),0); 
        while (l <= r) {
            a+=max(p[l],p[r]);
            l++;
            r--;
        }

        return a>(sum-a);
    }
};