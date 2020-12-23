"""
Question:
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

Idea:
"""

/*Solution 1: binary search + two pointer search for start and end
    Time: O(logn) / 0(n) (worst case)*/

vector<int> searchRange(vector<int>& nums, int target) {
//check boundary
    if (nums.empty()) return {-1, -1};

    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end - start) / 2;
        
    while (start < end - 1) {
        mid = start + (end - start) / 2;
        if (nums[mid] < target) {
                start = mid;
        } else if (nums[mid] > target) {
                end = mid;
        } else { 
            // search for the real start and end
            while (nums[start] != target && start < end) {start++;}
            while (nums[end] != target && end > start) {end--;}
            return {start, end};
        }
    }    

    if (nums[start] == target && nums[end] == target) {
            return {start, end};
    } 
    else if (nums[start] == target && nums[end] != target) {
            return {start, start};
    } 
    else if (nums[start] != target && nums[end] == target) {
            return {end, end};
    } 
    return {-1, -1};
}

/*Solution 2: use binary search twice to find the left and right boundary*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (right == nums.size() || nums[right] != target) return res;
        res[0] = right;
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        res[1] = right - 1;
        return res;
    }
};
