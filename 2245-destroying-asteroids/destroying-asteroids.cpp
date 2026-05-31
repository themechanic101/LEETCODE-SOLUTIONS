class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long t=mass;

        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<=t)t+=asteroids[i];
            else if(asteroids[i]>t)return false;
        }

        return true;
    }
};