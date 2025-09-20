class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size()!=goal.size())return false;
        string concatenated = s+s;
        

        int check=concatenated.find(goal);
        if(check==-1)return false;
        return true;
        
    }
};