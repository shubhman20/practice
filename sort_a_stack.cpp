/*QUESTION:- Given a stack, the task is to sort it such that the top of the stack has the greatest element.
Test case : 
Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
*/

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedInsert(stack<int>&s,int num){
    if(s.empty()||(!s.empty()&&s.top()<num)){
        s.push(num);
        return;
    }
    int val=s.top();
    s.pop();
    SortedInsert(s,num);
    s.push(val);
    
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty())
    return ;
   int num=s.top();
   s.pop();
   sort();
   SortedInsert(s,num);
   
}
