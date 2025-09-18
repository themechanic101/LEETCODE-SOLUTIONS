class Solution {
public:
    string removeOuterParentheses(string s) {
// FOR STACK BASED APPROACH WITH EXTRA SPACE
// if st.empty >> push it into  stack and dont add it into answer
// if !st.empty >>  push it into stack and add it into answer

// ((()())())

        // stack<char>st;
        // string ans; 
        // for(auto ch: s){
        //     if(ch == '('){
        //         if(!st.empty()){
        //             ans+=ch;
        //     }
        //     st.push(ch);
        //     }else{
        //         st.pop();
        //         if(!st.empty()){
        //             ans+=ch;            
        //         }
        //     }
        // }
        //   return ans;  

// SECOND APPROACH 
//  using counters
 int counter =0;
        string ans; 
        for(auto ch: s){
            if(ch == '('){
                if(counter!=0){
                    ans+=ch;
            }
            counter++;
            }else{
                counter--;
                if(counter!=0){
                    ans+=ch;            
                }
            }
        }
          return ans;  




        }
       
      
      
  
};