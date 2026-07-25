class Solution {
public:
    int maxProduct(int n) {
       int max1=-1,max2=-1;

        while(n>0){
            int temp=n%10;
           if(max1<=temp){
            max2=max1;
            max1=temp;
           }else if(max2<temp){
            max2=temp;
           }
            n/=10;
        }

    return max1*max2;
    }
};