class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
             queue<pair<string,int>> q;
        q.push({startGene,1});
        unordered_set<string>st(bank.begin(),bank.end());
        st.erase(startGene);

        while(!q.empty()){
            string word=q.front().first;
            int stop=q.front().second;
            q.pop();

            if(word==endGene)return stop-1;
            for( int i=0;i<word.size();i++){
                char real=word[i];
                for(char ch='A';ch<='Z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,stop+1});
                    }
                }

                word[i]=real;
            }
        }

        return -1;
    }
};

