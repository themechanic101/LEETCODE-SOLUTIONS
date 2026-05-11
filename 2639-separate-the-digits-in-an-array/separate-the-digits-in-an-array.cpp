class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
         vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int temp=nums[i];
            vector<int> arr;
            
            while(temp){
                int d=temp%10;
                arr.push_back(d);
                temp/=10;
            }
            reverse(arr.begin(),arr.end());
            for(int x:arr){
                ans.push_back(x);
            }
        }
        return ans;
    }
};