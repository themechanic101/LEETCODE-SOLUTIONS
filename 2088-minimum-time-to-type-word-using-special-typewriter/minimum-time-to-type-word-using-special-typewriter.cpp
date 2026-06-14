class Solution {
public:
    int minTimeToType(string word) {
        int time = 0;
        int prev = 0;
        for (int i = 0; i < word.size(); i++) {
            int clock = abs((word[i] - 'a') - prev);
            int anti = 26 - clock;
            time += min(clock, anti);
            prev = word[i] - 'a';
        }
        cout << time << endl;
        return time + word.size();
    }
};