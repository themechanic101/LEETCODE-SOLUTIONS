class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        string s= to_string(n);
        string result;
        
        if(n==0)return 0;

        for(char ch:s){
            int digit=ch-'0';
            sum+=digit;
            if(ch!='0')result.push_back(ch);
        }

        long long  x =stoll(result);

        return x*sum;
    }
};