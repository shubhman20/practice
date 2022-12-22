/*QUESTION:-
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index;
        if(target<nums[0]){
            index = 0;
            return 0;
        }
        else if(target>nums[nums.size()-1]){
            return nums.size();
        }
        int l=0,h=nums.size()-1;
        int mid;
        while(h-l>1){
            mid = l + (h-l)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }
        if(nums[l]>=target){
            index=l;
        }
        else if(nums[h]>=target){
            index=h;
        }
        
        return index;
    }
};
