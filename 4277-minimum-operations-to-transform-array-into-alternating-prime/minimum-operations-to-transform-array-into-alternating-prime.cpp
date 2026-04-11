class Solution {
public:
    bool isPrime(int x){
        if(x==1)return 0;
        int i=2;
        while(i*i<=x) {
            if(x%i==0)return 0;
            i++;
        }
        return 1;
    }
    int minOperations(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                while(!isPrime(nums[i])){
                    count++;
                    nums[i]+=1;
                }
            }else{
                while(isPrime(nums[i])){
                    count++;
                    nums[i]+=1;
                }
            }
        }
        return count;
    }
};