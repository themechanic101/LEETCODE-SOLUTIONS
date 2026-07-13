class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>st;

        for(int i:nums){
            st.insert(i);
            int rev=0;
            int temp=i;
            while(temp){
                 int d=temp%10;
           temp/=10;
           rev=rev*10+d;
            }
            st.insert(rev);
        }

        return st.size();
    }
};