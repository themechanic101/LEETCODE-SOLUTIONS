class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // vector<int>ans;
        // int i=0;
        // int j=0;

        // while(i<m && j<n){
           
        //     if(nums1[i]<=nums2[j]){
        //         ans.push_back(nums1[i]);
        //         i++;
        //     }else{
        //         ans.push_back(nums2[j]);
        //         j++;
        //     }
        // }
        // while(i<m){
        //     ans.push_back(nums1[i]);
        //     i++;
        //     }

        //     while(j<n){
        //         ans.push_back(nums2[j]);
        //         j++;
        //     }
        //     for(int i=0;i<m+n;i++){
        //         nums1[i]=ans[i];
        //     }

        int left=m-1;
        int right=0;

        while(left>0  && right<n){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left--,right++;
            }else{
                break;
            }
        }

        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.begin()+n);

        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(),nums1.begin()+m+n);
        
    }
};