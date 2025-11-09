class Solution {
public:
    void combination(string& tiles, vector<bool>&vis,int &cnt,string curr) {
        for (int i=0;i<tiles.size();i++) {
            if(vis[i]==true)continue;
            if (i>0 && tiles[i]==tiles[i-1] &&vis[i-1]==false)continue;
          
            vis[i]=true ;
            cnt++;
            combination(tiles,vis,cnt,curr+tiles[i]);
            vis[i]=false;   
        }
    
    }

public:
    int numTilePossibilities(string tiles) {
        vector<bool>vis(tiles.size(),false);
        sort(tiles.begin(),tiles.end());
        string curr="";
        int cnt=0;
        combination(tiles,vis,cnt,"");

        return cnt;
    }
};