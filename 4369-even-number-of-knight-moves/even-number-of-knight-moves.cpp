class Solution {
public:
    bool canReach(vector<int>& s, vector<int>& t) {
        return (abs(s[0]-t[0])+abs(s[1]-t[1]))%2==0;
    }
};