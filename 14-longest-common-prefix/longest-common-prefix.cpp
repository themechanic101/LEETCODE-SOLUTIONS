class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sorting and then iterating and  comapring on  the first and last  words/element of vector exp [ club , clue , clumsy sluster ,clutch] 
//  iterate over every word in word club and clutch
       sort(strs.begin(),strs.end());

        string first=strs[0], last=strs[strs.size()-1];
        int i=0;
        while( i<first.size() && i<last.size() && first[i]==last[i]){
            i++;
        }
        return first.substr(0,i);
        
    }
};