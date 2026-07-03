class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        int n=capacity.size();
        int ans=0;

        for(int i=0;i<n;i++)rocks[i]=capacity[i]-rocks[i];

        sort(rocks.begin(),rocks.end());

        for(int i=0;i<n;i++){
            if(rocks[i]==0)ans++;
            else if(a>=rocks[i]){
                ans++;
                a-=rocks[i];
            }
        }

        return ans;
    }
};