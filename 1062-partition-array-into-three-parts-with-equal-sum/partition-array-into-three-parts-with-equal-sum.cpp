class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total=0;
        for(int poojith:arr){
            total+=poojith;
        }
        if(total%3 !=0){
            return false;
        }
        int target=total/3;
        int sum=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==target){
                count++;
                sum=0;
            }
        } 
        return count>=3;
    }
};