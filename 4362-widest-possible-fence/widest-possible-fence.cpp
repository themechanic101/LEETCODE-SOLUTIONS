class Solution {
public:
    int maximumWidth(vector<int>& p) {
        unordered_map<int,int>cnt,res;

        for(int x:p){
            cnt[x]++;
            res[x]++;
        }


        for(auto &a:cnt){
            for(auto &b:cnt){
                int a1=a.first,b1=b.first;
                if(a1<b1){
                    res[a1+b1]+=min(cnt[a1],cnt[b1]);
                }
                if(a1==b1){
                    res[a1+b1]+=cnt[a1]/2;
                }
            }
        }


        int ans=0;

        for(auto t:res){
            ans=max(ans,t.second);
        }

        return ans;
    }
};