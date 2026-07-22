class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;

        int n=nums.size();

               for(int i=0; i < n; i++) {
            
            // To store the smallest value of subarray
            int smallest = nums[i];
            
            // To store the largest value of subarray
            int largest = nums[i];
            
            /* Nested loop to get all 
            subarrays starting from index i */
            for(int j=i; j < n; j++) {
                
                // Update the smallest value
                smallest = min(smallest, nums[j]);
                
                // Update the largest value
                largest = max(largest, nums[j]);
                
                // Update the sum
                sum += (largest - smallest);
            }
        }
        
        // Return the computed sum
        return sum;

    }
};