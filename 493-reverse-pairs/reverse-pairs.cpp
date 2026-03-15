class Solution {
public:
int cnt=0;
 void merge(vector<int>& arr, int low, int mid, int high) {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    void countpairs( vector<int>& arr,int low,int mid,int high){
        int right =mid+1;

        for(int i=low;i<=mid;i++){
            while(right<=high && arr[i]>1LL*2*arr[right])right++;
            cnt+=right-(mid+1);
        }
    }


void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;  
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        countpairs(arr,left,mid,right);

        // Merge sorted halves
        merge(arr, left, mid, right);
    
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);

        return cnt;
    }
};