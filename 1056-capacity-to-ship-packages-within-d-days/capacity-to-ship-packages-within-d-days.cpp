class Solution {
public:
int  possible(vector<int>& weights, int days,int capacity){
    int n=weights.size();

    int cnt=1;
    int load=0;

    for(int i=0;i<n;i++){
        if(load+weights[i]>capacity){
            cnt=cnt+1;
            load=weights[i];
        }else{
            load+=weights[i];
        }
    }
   
  

   return cnt;
    
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        
        int high;
        for(auto w:weights)high+=w;
   

        int ans=high;

        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(possible(weights,days,mid)<=days){
                
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return low;
    }
};