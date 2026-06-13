class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      int cnt = 0;
        map<int , int> mpp;
        for(auto a : nums)  mpp[a]++;
        int maxi = *max_element(nums.begin() , nums.end());
        int mini = *min_element(nums.begin() , nums.end());
        for(int i = maxi; i >= mini; i--){
            while(cnt < k and mpp[i] > 0) {cnt++; mpp[i]--;}
            if(cnt == k) return i;
        } 
        return -1;
    
    }
};