class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int>a;
        for(int i=1;i<=num/2;i++){
            if(num%i==0)a.push_back(i);
        }

        int sum=accumulate(a.begin(),a.end(),0);

        if(sum==num)return true;
        return false;
    }
};