class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int>freq(10,0);
        while(n){
            int digit=n%10;
            freq[digit]++;
            n/=10;
        }

        int score=0;
        for(int i=0;i<10;i++){
            score+=i*freq[i];
        }
        return score;
    }
};