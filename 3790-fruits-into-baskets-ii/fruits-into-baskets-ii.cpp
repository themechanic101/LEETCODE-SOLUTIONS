class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int cnt=0;
        vector<int>used(n,0);
       

        for(int i=0;i<n;i++){
            bool placed=false;
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j] && !used[j]){
                    used[j]=1;
                    placed=true;
                    
                    break;
                }

            }
            if(!placed)cnt++;
        }

        

        return cnt;
    }
};