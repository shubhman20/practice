/*QUESTION:-
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
*/


class Solution {
public:
    void combi(vector<vector<int>> &ans,vector<int> &temp,int n,int k,int idx){
        if(temp.size()==k&&n==0){
            ans.push_back(temp);
            return;
        }
        else if(temp.size()==k&&n==0){
            return;
        }
        else{
            while(idx<=9){
                temp.push_back(idx);
                combi(ans,temp,n-idx,k,++idx);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>temp;
        combi(ans,temp,n,k,1);
        return ans;
    }
};
