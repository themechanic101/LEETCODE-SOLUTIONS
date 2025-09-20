class Solution {
public:
    bool isIsomorphic(string s, string t) {
//  using teo hashmaps
        int m1[256]={0};
        int m2[256]={0};

        for(int i =0;i<s.size();i++){
            // comparing the last seen index 
            if(m1[s[i]]!=m2[t[i]]) return false;

            m1[s[i]]=i+1;
            m2[t[i]]=i+1;
        }
        return true;
        
    }
};