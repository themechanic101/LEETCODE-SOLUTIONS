class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int l_max=0;
        int r_max=0;
        int total=0;

        while(left<right){
            if(height[left]<height[right]){
                if(l_max>height[left]){
                    total+=l_max-height[left];
                    
                }else{
                    l_max=height[left];
                }
                left++;
            }else{
                if(r_max>height[right]){
                    total+=r_max-height[right];
                }else{
                    r_max=height[right];
                }

                right--;
            }
        }

        return total;
    }
};