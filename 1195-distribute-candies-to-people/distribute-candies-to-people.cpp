class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int x = 1, i = 0;
        while(candies != 0){
            if(i == ans.size()) i = 0;
            if(x <= candies){
                ans[i] = ans[i] + x;
                candies = candies - x;
                x++;
            }
            else{
                ans[i] = ans[i] + candies;
                break;
            }
            i++;
        }
        return ans;
    }
};