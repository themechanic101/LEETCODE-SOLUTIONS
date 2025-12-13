class Solution {
public:

bool validcode(string s){
    if(s.empty())return false;

    for(char &ch:s){
        if( !isalnum(ch)  && ch !='_')return false;
    }
    return true;
}
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,int>mp=
        {{"electronics",0},{"grocery",1},{"pharmacy",2},{"restaurant",3}};
       

       vector<pair<int,string>>temp;
       for(int i=0;i<code.size();i++){
        if(isActive[i] && mp.count(businessLine[i]) && validcode(code[i])){
            temp.push_back({mp[businessLine[i]],code[i]});
        }
       }

       sort(temp.begin(),temp.end());
       vector<string>result;

       for(auto &it:temp){
        result.push_back(it.second);
       }

       return result;
    }
};