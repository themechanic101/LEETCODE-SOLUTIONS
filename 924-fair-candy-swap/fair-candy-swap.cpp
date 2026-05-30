class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int a = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int b = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        int diff = (a - b) / 2; 

        
        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());

        for (int x : aliceSizes) {
            int y = x - diff;  
            if (bobSet.count(y)) {
                return {x, y};
            }
        }
        return {};
    }
};