class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int grpsize) {
        if( hand.size()%grpsize!=0)return false;

        map<int,int>mp;
        
        for(int &i:hand){
            mp[i]++;
            }
        auto it=mp.begin();


        while(it!=mp.end()){

            if(it->second==0){
                it++;
                continue;
            }
            int t=it->first;

            int cnt=it->second;

            for(int i=0;i<grpsize;i++){
                if(mp[t+i]<cnt)return false;

                mp[t+i]-=cnt;
            }

            it++;
        }

        return true;

    }
};