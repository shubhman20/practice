int minEle;
    stack<int> s,min_st;
        
       /*returns min element from stack*/
       int getMin(){
           if(min_st.empty()) return -1;
           return min_st.top();
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty()) return -1;
           if(min_st.top()==s.top()){
               min_st.pop();
           }
           int val = s.top();
           s.pop();
           return val;
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(min_st.empty()||x<=min_st.top()){
               min_st.push(x);
           }
           s.push(x);
           //Write your code here
           
       }
