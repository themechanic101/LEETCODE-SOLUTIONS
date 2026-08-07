class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int j=0;
        int n1=nums1.size(),n2=nums2.size();

       for(int i=0;i<n1;i++){
        if(j<i)j=i+1;
        while(j<n2 && nums2[j]>=nums1[i]){
            j++;
        }
        ans=max(ans,j-i-1);
       }

       return ans;
    }
};