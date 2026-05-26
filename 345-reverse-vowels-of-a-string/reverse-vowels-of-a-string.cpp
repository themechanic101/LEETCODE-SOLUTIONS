class Solution {
public:
    string reverseVowels(string s) {
       set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                             'A', 'E', 'I', 'O', 'U'};

        int i=0,j=s.size()-1;

        while(i<j){
            char l=s[i];
            char r=s[j];

            if(vowels.find(l)!=vowels.end() && vowels.find(r)!= vowels.end() && i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }

            if( vowels.find(r)==vowels.end() && i<j)j--;
             if( vowels.find(l)==vowels.end() && i<j)i++;
        }

        return s;
    }
};