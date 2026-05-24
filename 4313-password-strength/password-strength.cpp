class Solution {
public:
    int passwordStrength(string password) {
        int ans=0;
        string l="abcdefghijklmnopqrstuvwxyz";
        string u="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string d="0123456789";
        string c="!@#$";
        for(char ch:l){
            if(password.find(ch)!=-1) ans+=1;
        }
        for(char ch:u){
            if(password.find(ch)!=-1) ans+=2;
        }
        for(char ch:d){
            if(password.find(ch)!=-1) ans+=3;
        }
        for(char ch:c){
            if(password.find(ch)!=-1) ans+=5;
        }
        return ans;
    }
};