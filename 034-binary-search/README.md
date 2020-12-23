# Binary Searrch - Leetcode 45
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.<br>
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

**stragety:** <br/>
- Binary Search Template
```
int BinarySearch (int[] nums, int target) {
    if(nums.empty()) {return -1;}
    int lPtr = 0, rPtr = nums.size() - 1
}

```
- [TwoSum](#twosum)
  - [Double Pointer](#double-pointer)
  - [HashTable](#hashtable)

- [Three Sum](#three-sum)
- [Four Sum](#four-sum)
- [nSum](#n-sum)

**Summary**

:star: use ```lPtr ```in stead of ```left``` to prevent the case that mix the use of nums[left] and ```left``` <br>
:star: The utility of **while(```start + 1 < end```)** and also updating the mPtr to be lPtr/rPtr all to prevent ??runtime errors


### Two Sum
:star: if the array is sorted: -> use two pointe<br>
:star: if the return value is the index: -> use HashMap
#### Double Pointer
Sort the array, use two pointers stragety(相向双指针)<br>
- Time Compelxity: 
    - unsorted array: O（nlogn)(排序) + O(n)(双指针) = O(nlogn)<br>
    - sorted array: O(n)
- Space Complexity: O(1)<br>

<img src="image/2sum-pointer.png" width="550">

#### HashTable
- Time Compelxity: O(n)<br>
- Space Complexity: O(n)<br>

|            | map     | unordered_map |
| ----------- | ----------- | ----------- |
|Ordering |increasing  order (by default)| no ordering
|Implementation  | Self balancing BST( like Red-Black Tree )| Hash Table
search time     | log(n)              | O(1) -> Average<br>O(n) -> Worst Case|
|Insertion time  | log(n) + Rebalance  | Same as search|
|Deletion time   | log(n) + Rebalance  | Same as search|

```
vector<int> twoSum(vector<int>& numbers, int target) {
	unordered_map<int, int> hash; //Number, Index
        
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

		if (hash.find(numberToFind) != hash.end()) 
			return  {hash[numberToFind] ,i };

		hash[numbers[i]] = i; //put number into the map
	}
	return {};
    }
```
### Three Sum
Traverse every number in sorted array to be the first number, use twoSum to compute the rest two numbers
<img src="image/3sum.png" width="550">

### Four Sum
Traverse every number in sorted array as the first number, call three sum
### n Sum
```
/* 注意：调用这个函数之前一定要先给 nums 排序 */
vector<vector<int>> nSumTarget(
    vector<int>& nums, int n, int start, int target) {
    int sz = nums.size();
    vector<vector<int>> res;
    // 至少是 2Sum，且数组大小不应该小于 n
    if (n < 2 || sz < n) return res;
    // 2Sum 是 base case
    if (n == 2) {
        // 双指针那一套操作
        int lo = start, hi = sz - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if (sum < target) {
                while (lo < hi && nums[lo] == left) lo++;
            } else if (sum > target) {
                while (lo < hi && nums[hi] == right) hi--;
            } else {
                res.push_back({left, right});
                while (lo < hi && nums[lo] == left) lo++;
                while (lo < hi && nums[hi] == right) hi--;
            }
        }
    } else {
        // n > 2 时，递归计算 (n-1)Sum 的结果
        for (int i = start; i < sz; i++) {
            vector<vector<int>> 
                sub = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
            for (vector<int>& arr : sub) {
                // (n-1)Sum 加上 nums[i] 就是 nSum
                arr.push_back(nums[i]);
                res.push_back(arr);
            }
            while (i < sz - 1 && nums[i] == nums[i + 1]) i++;
        }
    }
    return res;
}

```
n == 2 时是 twoSum 的双指针解法，n > 2 时就是穷举第一个数字，然后递归调用计算 (n-1)Sum，组装答案。