class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>j;
        map<char,int>s;
        int cnt=0;

        for(int i=0;i<jewels.size();i++){
             j[jewels[i]]++;
        }
         for(int i=0;i<stones.size();i++){
             s[stones[i]]++;
        }

        for(char c:jewels){
            if(s.find(c)!= s.end()){
                cnt+=s[c];
            }
        }

        return cnt;
    }
};