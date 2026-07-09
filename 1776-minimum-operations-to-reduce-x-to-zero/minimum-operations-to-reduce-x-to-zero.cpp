class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();

        int total=accumulate(nums.begin(),nums.end(),0);
        int target=total-x;
        if (target < 0) return -1;       
        if (target == 0) return n;       

        int maxi = -1; 
    
        int sum=0;
        int l=0;

        //if(total<x)return -1;

        for(int i=0;i<n;i++){
           sum+=nums[i];

           while(sum>target){
            sum-=nums[l];
            l++;
           }

           if(sum==target){
            maxi=max(maxi,i-l+1);
           }
        }
        
        return (maxi==-1)?-1:n-maxi;
    }
};