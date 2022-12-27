/*QUESTION:-
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/



class Solution {
public:
    void subgen(vector<int>&nums,vector<vector<int>> &ans,vector<int>&temp,int idx){
        // if(idx==nums.size()){
            ans.push_back(temp);
        //     return;
        // }
        // if(idx>nums.size())
        //     return;
        for(int i=idx;i<nums.size();i++){
            if(i>idx&&nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            subgen(nums,ans,temp,i+1);
            temp.pop_back();
        }
            
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        subgen(nums,ans,temp,0);
        return ans;
    }
};
