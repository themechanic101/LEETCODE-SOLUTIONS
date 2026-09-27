class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long  s=accumulate(source.begin(),source.end(),0LL);
        long long  t=accumulate(target.begin(),target.end(),0LL);
        return s==t;
    }
};