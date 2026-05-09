class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        auto score=0,counter=0;
        for(string &x:events){
            if(isdigit(x[0])){
                score+=stoi(x);
            }else if(x=="WD" or x=="NB"){
                score+=1;
            }else if(x=="W"){
                ++counter;
            }
            if(counter==10)
                break;
        }
        return {score,counter};
    }
};