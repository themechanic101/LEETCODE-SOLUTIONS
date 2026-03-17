class Solution {
public:
typedef long long ll;
ll calculateTotalHours(vector<int>& a, int hourly) {
        ll totalHours = 0;
        for (int pile : a) {
        
            totalHours += ceil((double)pile / hourly);
        }
        return totalHours;
     
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int high=*max_element(piles.begin(),piles.end());
       ll ans=high;
       int low=1;

        while (low <= high) {
            int mid = (low + high) / 2;
            ll totalH = calculateTotalHours(piles, mid);

      
            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            }
          
            else {
                low = mid + 1;
            }
        }

      
       return ans;
    }
};