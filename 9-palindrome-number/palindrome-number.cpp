class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long rev=0;
        long long num=x;
     while (num != 0) {
    rev = rev * 10 + num % 10; // Add last digit
    num = num / 10;            // Remove last digit
}
  return (rev==x);
       
    }
};