"""
Question:
Given an array of integers nums, sort the array in ascending order.
Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
 
"""
//Solution 1: Quick Sort
'''
Idea: 先整体后局部 recurrisive put smaller number to the left and larger number 
    to the right
1. let startIdx be 0 and endIdx be nums.size() -1, pivot = nums[startIdx + (endIdx - startIdx) / 2];
2. move left and right pointer until the number that they pointed at should be swap and lPtr <= rPtr
3. swap the number that they pointed at, call the quicksort again to sort the array after swap
'''
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1) {
            return nums;
        }
        quickSort(nums, 0, nums.size() - 1);
        return nums;
     }
private:
    void quickSort(vector<int>& nums, int startIdx, int endIdx) {
        if(startIdx > endIdx) {
            return;
        }
        int lPtr = startIdx, rPtr = endIdx;
        // 1. pivot != nums[startIdx] / nums[endIdx];
        // get value not index
        int pivot = nums[startIdx + (endIdx - startIdx) / 2];
        // 2. left <= right not left < right (stack overflow)
        while (lPtr <= rPtr) {
            // 3. nums[lPtr] < pivot instead of <= to prevent stack overflow(when all equal number, will                have unequal distribution)
            while (lPtr <= rPtr && nums[lPtr] < pivot) {
                lPtr ++;
            }
            while (lPtr <= rPtr && nums[rPtr] > pivot) {
                rPtr --;
            }
            // 4. remember to check if lPtr <= rPtr, if not, break the while loop 
            //swap
            if (lPtr <= rPtr) {
                swap(nums[lPtr], nums[rPtr]);
                lPtr ++; 
                rPtr --;      
            }
        }
        quickSort(nums, startIdx, rPtr);
        quickSort(nums, lPtr, endIdx);
        return;
        
    }
};
//Solution 2: Merge Sort