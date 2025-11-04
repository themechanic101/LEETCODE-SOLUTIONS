class Solution {
public:
    int addDigits(int num) {
// all number are epossitive
        while(num>9){
            int ans=0 ,digit;
            while(num){
                digit=num%10;
                ans+=digit;
                num=num/10;
            }
         num=ans;
        }
        return num;
        
    }
};