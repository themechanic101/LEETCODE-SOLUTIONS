class Solution {
public:
    bool judgeCircle(string moves) {
        int starthor = 0;
        int startvert = 0;
        for(auto i:moves){
            if(i == 'R'){
                starthor++;
            }
            if(i == 'L'){
                starthor--;
            }
            if(i == 'U'){
                startvert++;
            }
            if(i == 'D'){
                startvert--;
            }
            
        }
        return(!starthor && !startvert);
    }
};