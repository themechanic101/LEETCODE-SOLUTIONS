class DSU{
    public:
    vector<int>par,size;
    DSU(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int find(int x){
        if(par[x]==x)return x;

        return par[x]=find(par[x]);
    }


    void unionbysize(int x ,int y){
        int px=find(x);
        int py=find(y);

        if(px==py)return;

        if(size[px]>size[py]){
            par[py]=par[px];
            size[px]+=size[py];
        }else{
            par[px]=par[py];
            size[py]=size[px];
        }
    }


};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size(); 
        int ans=1;
        unordered_map<int,int>mp;
        int i=*max_element(nums.begin(),nums.end());
        DSU ds(i);

        for(auto c:nums){
            for(int k=2;k<=sqrt(c); k++){
                if(c%k==0){
                    ds.unionbysize(c,k);
                    ds.unionbysize(c,c/k);
                }
            }
        }

        for(int i=0;i<n;i++){
            ans=max(ans,++mp[ds.find(nums[i])]);
        }

        return ans;
    }
};