class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int cells=n*n;
        int cnt=0;

        for(int i=1;i<=cells;i++){
            if(i*w<=maxWeight)cnt++;
        }

        return cnt;
    }
};