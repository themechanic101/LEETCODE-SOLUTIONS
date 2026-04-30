class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;

        int target = total / 4;
        
        if (*max_element(matchsticks.begin(), matchsticks.end()) > target)
            return false;

        
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        vector<int> sides(4, 0); 

        return backtrack(matchsticks, 0, sides, target);
    }

private:
    bool backtrack(vector<int>& matchsticks, int index, vector<int>& sides, int target) {
        
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target &&
                   sides[2] == target && sides[3] == target;
        }

        int stick = matchsticks[index];

        
        for (int i = 0; i < 4; ++i) {
            
            if (sides[i] + stick > target) continue;

            if (i > 0 && sides[i] == sides[i - 1]) continue;

            
            sides[i] += stick;

        
            if (backtrack(matchsticks, index + 1, sides, target))
                return true;

        
            sides[i] -= stick;
        }

    
        return false;
    }
};