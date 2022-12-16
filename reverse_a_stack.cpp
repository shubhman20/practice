//User function Template for C++
/*Reverse a stack using recursion*/
class Solution{
public:
    void rinsert(stack<int> &St,int val){
        if(St.empty()){
            St.push(val);
            return;
        }
        int t = St.top();
        St.pop();
        rinsert(St,val);
        St.push(t);
    }
    
    void Reverse(stack<int> &St){
        // stack<int> s;
        if(St.empty())
            return;
        if(St.size()==1){
            return;
        }
        int val=St.top();
        St.pop();
        Reverse(St);
        rinsert(St,val);
    }
};
