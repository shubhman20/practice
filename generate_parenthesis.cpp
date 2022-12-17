/*QUESTION:-
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/



class Solution {
public:
    void generate(vector<string> &ans,int o,int c,string &a,int &n){
        if(a.size() == 2*n){
            ans.push_back(a);
            return;
        }
        if(o<n){
            a.push_back('(');
            o++;
            generate(ans,o,c,a,n);
            // o++
            a.pop_back();
            o--;
        }
        if(c<o&&c<n){
            a.push_back(')');
            c++;
            generate(ans,o,c,a,n);
            // c++;
            a.pop_back();
            c--;
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        // stack<char>s;
        string a="";
        generate(ans,0,0,a,n);
        return ans;
    }
};
