class Solution {
public:
typedef long long ll;

bool check(long long mid, vector<int>& workerTimes,int mountainHeight){
    ll h=0;

   for (auto &t : workerTimes) {
    double val = 2.0 * mid / t + 0.25;
    if (val < 0) val = 0; 
    h += (ll)(sqrt(val) - 0.5);
    if (h >= mountainHeight) return true;
}

    return h>=mountainHeight;
}
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll maxtime=(ll)*max_element(workerTimes.begin(),workerTimes.end());
        ll l=1;
        ll r=maxtime*mountainHeight*(mountainHeight+1)/2;
       ll result=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(check(mid,workerTimes,mountainHeight)){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return result;
    }
};