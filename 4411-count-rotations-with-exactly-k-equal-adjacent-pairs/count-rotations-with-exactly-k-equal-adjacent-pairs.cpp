class Solution {
public:
    int countRotations(string s, int k) {
        string s1=s+s;
        int n=s.size();
        int ans=0,i=0;

        while(i+n<s1.size()){
            int score=0;
            for(int j=0;j<n-1;j++){
                if(s1[i+j]==s1[i+j+1]){
                     score++;
                }
            }

            if(score==k)ans++;
            i++;
        }

        return ans;
    }
};