class Solution {
public:
    long long appealSum(string s) {
        int n=s.size();

        long long ans=0,curr=0;
        long long prev[26]={};

        for(int i=0;i<n;i++){
            curr+=i+1-prev[s[i]-'a'];
            prev[s[i]-'a']=i+1;
            ans+=curr;
        }

        return ans;
    }
};