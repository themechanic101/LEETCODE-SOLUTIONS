class Solution {
public:
    string destCity(vector<vector<string>>& paths)
    {
        unordered_map<string, string> freq;

        for(uint8_t i = 0 ; i < paths.size() ; i++)
            freq[paths[i][0]] = paths[i][1];

        string s = paths[0][0];

        while(freq.count(s))
            s = freq[s];

        return s;
    }
};