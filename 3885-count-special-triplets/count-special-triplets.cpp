class Solution {
public:
int M = 1e9+7;
    int specialTriplets(vector<int>& nums) {
     unordered_map<int,int>map_left;
          unordered_map<int,int>map_right;
          int result=0;

          for(int num:nums)
          map_right[num]++;


          for(int num: nums){
             map_right[num]--;

             int left=map_left[num*2];
             int right=map_right[num*2];

             result=(result+(1LL*left*right))%M;

             map_left[num]++;
          }
 return result;
    }
};