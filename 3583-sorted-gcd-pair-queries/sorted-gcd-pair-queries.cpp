class Solution {
public:
typedef long long ll;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxval=*max_element(nums.begin(),nums.end());

        //freq
        vector<ll>freq(maxval+1,0);

        for(int x:nums)freq[x]++;

        vector<ll>divcnt(maxval+1,0);

        for(int g=1;g<=maxval;g++){
            for(int x=g;x<=maxval;x+=g){
                divcnt[g]+=freq[x];
            }
        }



        vector<ll>exact(maxval+1,0);

        for(int g=maxval;g>=1;g--){
            exact[g]=divcnt[g]*(divcnt[g]-1)/2; ///nc2
            for(int m=2*g;m<=maxval;m+=g){
                exact[g]-=exact[m];
                //exact[2]=pairsdiv[2]-exact[4 or 2*@ or 2g ]-exact[3g].........
            }
        }


        vector<ll>prefix(maxval+1,0);

        for(int g=1;g<=maxval;g++){
            prefix[g]=prefix[g-1]+exact[g];
        }

        vector<int>ans;

         for (long long q : queries) {
            // first gcd whose prefix > q
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};