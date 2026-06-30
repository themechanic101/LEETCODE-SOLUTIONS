class Solution {
public:
    long long countVowels(string s) {
   long long ans=0;
   long long n=s.size();

   for(long long i=0;i<n;i++){
       if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ){
        ans+=(int)(i+1)*(n-i);
       }
   }

   return ans;


    }
};