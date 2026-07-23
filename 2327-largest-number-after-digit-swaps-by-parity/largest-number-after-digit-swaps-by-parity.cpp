class Solution {
public:
    int largestInteger(int num) {
        int t = num ;
        priority_queue<int> o ;
        priority_queue<int> e ;
        while(t){
            int d = t% 10 ;
            t = t/10 ;
            if( d%2 == 0 ) e.push(d) ;
            else o.push(d) ;
        }
        string s = to_string(num) ;
        for(char c : s ){
            if( (c-'0' )% 2 == 0 ){
                t = t*10 + e.top() ;
                e.pop() ;
            }
            else{
                t = t*10 + o.top() ;
                o.pop() ;
            }
        }
        return t ;
    }
};