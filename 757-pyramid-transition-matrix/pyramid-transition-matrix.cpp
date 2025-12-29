class Solution {
public:
unordered_map<string,bool>t;

bool solve(string curr,int idx,string above,unordered_map<string,vector<char>>&mp){
   string key=curr+"_"+to_string(idx)+"_"+above;
   if (t.count(key)) return t[key];

   if(curr.size()==1)return true;


   if(idx== curr.size()-1) return  t[key]=solve(above,0,"",mp);

   string pair=curr.substr(idx,2);

   if(!mp.count(pair))return t[key]=false;

   for(char &ch: mp[pair]){
    above.push_back(ch);
    if(solve(curr,idx+1,above,mp)== true)return t[key]= true;
    above.pop_back();
   }

   return t[key]=false;
}
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>>mp;

        for(auto &pattern:allowed){
            mp[pattern.substr(0,2)].push_back(pattern[2]);
        }

        return solve(bottom,0,"",mp);
    }
};