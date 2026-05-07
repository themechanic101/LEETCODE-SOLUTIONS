class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(char chh:magazine){
            mp[chh]++;
        }  
        for(char ch:ransomNote){
            if(mp[ch]>0)
            mp[ch]--;
            else return false;
        }    
        return true;
        
    }
};