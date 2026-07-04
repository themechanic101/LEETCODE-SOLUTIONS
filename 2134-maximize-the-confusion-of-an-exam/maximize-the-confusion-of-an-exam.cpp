class Solution {
public:

int solve(string &a,int k,char ch){
    int l=0;
    int cnt=0;
    int maxi=0;

    for(int r=0;r<a.size();r++){
        if(a[r]==ch)cnt++;

        while(cnt>k){
            if(a[l]==ch)cnt--;
            l++;
        }

        maxi=max(maxi,r-l+1);
    }

    return maxi;
}
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey,k,'T'),solve(answerKey,k,'F'));
    }
};