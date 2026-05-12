class Solution {
public:
    int alternateDigitSum(int n) {
         string s=to_string(n);
       int sum=0;
       int sign=1;
       for(int i=0;i<s.size();i++){
          int a=s[i]-'0';
          sum=sum+a*sign;
          sign*=-1;
       } 
       return sum;
    }
};