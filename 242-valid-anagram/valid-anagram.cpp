#include<bits/stdc++.h>
class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());  //O(nlogn ) is the tc 
        // sort(t.begin(),t.end());

        // for(int i =0; i<max(s.size(),t.size());i++){
        //     if(s[i]!=t[i]) return false;
        // }

        // return true;

        if(s.size()!=t.size()) return false;

        unordered_map<char,int>map;

        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        for (int i=0 ;i<t.size();i++){
            if(map.find(t[i])!= map.end()){
                map[t[i]]--;
            }else{
                return false;
            }  
        }

        for (auto items : map){
            if(items.second!=0)return false; 
        }
          return true;
        
    }
};