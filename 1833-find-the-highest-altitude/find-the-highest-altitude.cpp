class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int ans=0;
        int pref=0;

        for(int c:gain){
            pref+=c;
            ans=max(pref,ans);
        }

        return ans;
    }
};