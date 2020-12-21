"""
Question:
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:

Input: nums = []
Output: []

Idea:
1. sort the array
2. traverse the array, let the traversed value to be first value of the triplets
2. two sum, find two numbers sum up to be target (-i value)
    - two pointer, one point to the left one to the right
    - if sum of the two < target, left pointer move right, vice versa
    - if sum of the two == target, push back to the result
"""
class Solution {
private:
    vector<vector<int>> twoSum(vector<int>& nums, int firstIdx) {
        vector<vector<int>> twoSumResult;
        int target = - nums[firstIdx];
        int lPtr = firstIdx + 1;
        int rPtr = nums.size() - 1;

        
        while(lPtr < rPtr) {
            int sum = nums[lPtr] + nums[rPtr];
            int left = nums[lPtr];
            int right = nums[rPtr];
            
            if (sum < target) {
                while(lPtr < rPtr && nums[lPtr] == left) {
                    lPtr ++;
                }
            } 
            else if (sum > target) {
                while(lPtr < rPtr && nums[rPtr] == right) {
                    rPtr --;
                }
            }
            else {
                vector<int> result = {nums[lPtr], nums[rPtr]};
                twoSumResult.push_back(result);
                //update lPtr&rPtr:
                while(lPtr < rPtr && nums[lPtr] == left) {
                    lPtr ++;
                }
                while(lPtr < rPtr && nums[rPtr] == right) {
                    rPtr --;
                }
                
            }            
        }
        return twoSumResult;
    }
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSumResult;
        if(nums.empty() || nums.size() < 3) {
            return threeSumResult;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            vector<vector<int>>twoResult = twoSum(nums, i);
            if (!twoResult.empty()) {
                for (int j = 0; j < twoResult.size(); j++) {
                    vector<int> result = {nums[i], twoResult[j][0], twoResult[j][1]};
                    threeSumResult.push_back(result);
                    
                }
            }
        }
        return threeSumResult;
        
    }
};