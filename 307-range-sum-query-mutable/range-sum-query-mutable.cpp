class NumArray {
public:
vector<int>bit,nums;
int n;
    NumArray(vector<int>& nums) {
       this->n=nums.size();
       this->nums=nums;
       bit.assign(n+1,0);

       for (int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
        
    }
      void add(int i, int val) {
        for (; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }
    
    void update(int index, int val) {
       int diff = val - nums[index]; 
        nums[index] = val;
        add(index + 1, diff);
    }
     int prefixSum(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
       return prefixSum(right+1)-prefixSum(left);

        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */