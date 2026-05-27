class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>st;
        for(int i=0;i<candyType.size();i++){
            st.insert(candyType[i]);
        }
        int sz=st.size();
        int n=candyType.size()/2;

        return min(n,sz);
        
    }
};