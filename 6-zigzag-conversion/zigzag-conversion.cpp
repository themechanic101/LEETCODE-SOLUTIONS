class Solution {
public:
    string convert(string s, int nr) {
        if(nr==1 || s.size()<=nr)return s;

        int n=s.size();

        vector<string>rows(min(nr,n));

        int curr=0;
        bool goindown=false;

        for(char c:s){
            rows[curr]+=c;

            if(curr==0 || curr==nr-1){
                goindown=!goindown;
            }

            curr+=goindown?1:-1;
        }

        string result="";
        for(auto str:rows){
            result+=str;
        }

        return result;
    }
};