class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        //st.erase(beginWord);

        while(!q.empty()){
            string word=q.front().first;
            int stop=q.front().second;
            q.pop();

            if(word==endWord)return stop;
            for( int i=0;i<word.size();i++){
                char real=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,stop+1});
                    }
                }

                word[i]=real;
            }
        }

        return 0;
        
    }
};