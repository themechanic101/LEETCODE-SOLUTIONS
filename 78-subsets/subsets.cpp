class Solution {
public:
void solution(vector<int>& nums, vector<vector<int>>& ans,int index, vector<int>&vec){
    
    if(index==nums.size()){
        ans.push_back(vec);
        return;
    }
    vec.push_back(nums[index]);
    solution(nums,ans,index+1,vec);
    vec.pop_back();
    solution(nums,ans,index+1,vec);


}
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>vec;
        int index=0;

        solution( nums,ans,index,vec);
        return ans;
    }
};