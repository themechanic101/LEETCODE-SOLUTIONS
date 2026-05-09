class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0,cnt=0;
        vector<int> ans;
        for(int i=0;i<events.size();i++){
            
            if(events[i]=="0" ||events[i]=="1" || events[i]=="2" || events[i]=="3" ||events[i]=="4"||events[i]=="5" ||events[i]=="6" ){
                score+=stoi(events[i]);
            }
            else if(events[i]=="W") {
                cnt++;
                if(cnt==10) break;
            }
            else if(events[i]=="WD") score++;
            else if(events[i]=="NB") score++;

        }
        ans.push_back(score);
        ans.push_back(cnt);
        return ans;
        
    }
};