/*QUESTION-
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/



class Solution {
public:
    void combi(int idx,vector<vector<int>>&ans,int target,vector<int>&candidates,vector<int>&temp){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            combi(idx,ans,target-candidates[idx],candidates,temp);
            temp.pop_back();
        }
        combi(idx+1,ans,target,candidates,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        combi(0,ans,target,candidates,temp);
        return ans;
    }
};
