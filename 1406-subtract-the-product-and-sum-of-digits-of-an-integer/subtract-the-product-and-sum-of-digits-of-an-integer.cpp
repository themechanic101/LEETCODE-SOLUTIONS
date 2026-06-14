class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro=1,sum=0;
        int temp=n;
        while(temp){
            int d=temp%10;
            sum+=d;
            pro*=d;
            temp/=10;
        }
        int diff=pro-sum;
        return diff;
    }
};