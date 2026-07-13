class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;

        string s="123456789";

        for(int i=0;i<s.size();i++){
            string curr="";
            for(int j=i;j<s.size();j++){
                curr+=s[j];
                int temp=stoi(curr);
                if(temp>=low && temp<=high)ans.push_back(temp);
            }
        }
sort(ans.begin(),ans.end());
        return ans;
    }
};