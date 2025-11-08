class Solution {
public:
    void combination(string& tiles, vector<bool>&vis,unordered_set<string>&result,string curr) {
        result.insert(curr);
        for (int i=0;i<tiles.size();i++) {
            if(vis[i]==true)continue;
            // if (i>0 && tiles[i]==tiles[i-1] &&vis[i-1]==false)continue;
          
            vis[i]=true ;
            curr.push_back(tiles[i]);
            combination(tiles,vis,result,curr+tiles[i]);
            vis[i]=false;
            curr.pop_back();
        }
    
    }

public:
    int numTilePossibilities(string tiles) {
        vector<bool>vis(tiles.size(),false);
        unordered_set<string>result;
        sort(tiles.begin(),tiles.end());
        string curr="";
        int cnt=0;
        combination(tiles,vis,result,"");

        return result.size()-1;
    }
};