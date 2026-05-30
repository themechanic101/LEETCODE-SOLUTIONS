class Solution {
public:
    int arrangeCoins(int n) {

        long long left = 1;
        long long right = n;

        while(left <= right){

            long long mid = (left + right) / 2;

            long long coinneed = mid * (mid + 1) / 2;

            if(coinneed == n)
                return mid;

            if(coinneed < n){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return right;
    }
};