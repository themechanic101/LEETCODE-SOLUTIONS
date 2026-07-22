class Solution {
public:

vector<int> f_nse(vector<int>&arr){
int n=arr.size();
vector<int>ans(n);
stack<int>st;


for(int i=n-1;i>=0;i--){
       while(!st.empty() && arr[st.top()]>=arr[i])st.pop();

       ans[i]=!st.empty()?st.top():n;

       st.push(i);
}

return ans;
}


vector<int> f_pse(vector<int>&arr){
    int n=arr.size();
    stack<int>st;

    vector<int>ans(n);

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i])st.pop();

        ans[i]=!st.empty()?st.top():-1;

        st.push(i);
    }

    return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int M =1e9+7;
        int sum=0;


        vector<int>pse=f_pse(arr);
        vector<int>nse=f_nse(arr);

        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;

            long long  freq=1LL*left*right;
            long long val=(arr[i]*freq*1LL)%M;

            sum=(sum+val)%M;
        }

       
        return sum%M;
    }
};