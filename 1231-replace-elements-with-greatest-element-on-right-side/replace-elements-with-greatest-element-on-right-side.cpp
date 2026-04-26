class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
         int n=arr.size();
        vector<int> suffixMax(n);
        suffixMax[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            suffixMax[i]=max(suffixMax[i+1],arr[i+1]); 
        }
        
        return suffixMax;
    }
};