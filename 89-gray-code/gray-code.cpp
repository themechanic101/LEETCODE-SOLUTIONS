class Solution {
public:

    vector<int> grayCode(int n) {
        vector<int>arr;

        int total= 1<<n;
        for(int i=0;i<total;i++){
            int t=i ^(i>>1);
            arr.push_back(t);
        }

        return arr;
    }
};