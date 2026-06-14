class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        const long long MOD = 1'000'000'007;

        unordered_map<int, long long> map1;
        unordered_map<int, long long> map2;

        int px = 0;
        long long ways1 = 0, ways2 = 0;

        for (int val : nums) {
            px ^= val;

            long long newWays1 = map2.count(px ^ target1)
                                     ? map2[px ^ target1]
                                     : 0;

            if (px == target1)
                newWays1 = (newWays1 + 1) % MOD;

            long long newWays2 = map1.count(px ^ target2)
                                     ? map1[px ^ target2]
                                     : 0;

            map1[px] = (map1[px] + newWays1) % MOD;
            map2[px] = (map2[px] + newWays2) % MOD;

            ways1 = newWays1;
            ways2 = newWays2;
        }

        return (ways1 + ways2) % MOD;
    }
};