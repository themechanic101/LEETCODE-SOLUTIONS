class Solution {
public:
    string convertToBase7(int num) {
        string ans="";

        bool sign =num<0;

        if(num==0)return "0";
    
        
           int  temp=abs(num);
    

        while(temp>0){
            int x=temp%7;
            ans.push_back('0'+x);
            temp/=7;
        }

        if(sign){
            ans.push_back('-');
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};