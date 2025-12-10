class Solution {
public:
int M=1e9+7;
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        int first=complexity[0];
        for(int i=1;i<n;i++){
            if(first>=complexity[i])return 0;
        }
        long long fact=1;
        for(int i=1;i<n;i++){
            fact=(fact*i)%M;
        }
        return fact;
    }
};