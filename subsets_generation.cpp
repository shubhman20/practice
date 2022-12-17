/*QUESTION:-
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/



class Solution {
public:
    void subset(vector<vector<int>>&ans,vector<int>&nums,int idx,vector<int>&temp){
        if(idx==nums.size()||temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subset(ans,nums,idx+1,temp);
        temp.pop_back();
        subset(ans,nums,idx+1,temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        subset(ans,nums,0,temp);
        return ans;
    }
};
