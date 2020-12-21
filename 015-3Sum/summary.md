## 3Sum - Leetcode 15

### Ideas: 2Sum --> nSum
(one stragety from two sum to n sum)[https://leetcode-cn.com/problems/3sum/solution/yi-ge-fang-fa-tuan-mie-by-labuladong/] 
**2Sum**

# 3Sum - Leetcode 15
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:

Input: nums = []
Output: []

**stragety:** <br/>
[from two Sum to n Sum](https://leetcode-cn.com/problems/3sum/solution/yi-ge-fang-fa-tuan-mie-by-labuladong/)


- [TwoSum](#twosum)
  - [Double Pointer](#double-pointer)
  - [HashTable](#hashtable)

- [ThreeSum](#three-sum)

- [nSum](#n-sum)

**Summary**
- first use ```sort(arr.begin(), arr.end())``` to sort the unsorted array
- to make sure the solution is unique, rememebr to move the pointer when meet duplicate number using stragety like this:
    ```
    // eliminate duplicate of first number of the triplets
    for (int i = 0; i <= nums.size() - 3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
                continue;
        }
        ....
    // elimate duplicate in twoSum
    1) in while loop, store the left and right value
        if (sum < target) {
            while (lo < hi && nums[lo] == left) lo++;
        } 
    }
    ```
    :stars:<br/>
    :bowtie:

作者：labuladong
链接：https://leetcode-cn.com/problems/3sum/solution/yi-ge-fang-fa-tuan-mie-by-labuladong/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

    ```
- pytest
- sklearn
- pandas

### TwoSum

This project aims to identify how muscles are synergistically activated at the arm during a multi-joint task.

#### Double Pointer

While seemingly simple, a motor task, such as retrieving an object from a high shelf, is very complicated. To achieve this task, movement-related signals are generated from the motor cortex of our brain and relayed to muscle fibers via motor neurons. In turn, muscles contract and the arm is raised and extended. There are more than 600 muscles in our body. Instead of controlling each muscle individually, our brain is thought to recruit these muscles in set groups. The activation of muscles in this grouped manner is termed muscle synergies and is part of a hierarchical control strategy. Activation of muscle synergies, rather than individual muscles, allows for a simplified control of one’s limb. In this work, the focus is on muscle activation at the arm. Specifically, the goal is to determine how muscles concurrently activate when an individual abducts at the shoulder and flexes at the elbow. As such, we can determine normal muscle activation patterns in a population that is neurologically and orthopaedically intact.

#### HashTable

#### Three Sum

<img src="src/image/readme/system.png" width="850">

The experimental setup, as shown in Figure 3, was comprised of a custom mechatronic system, a monitor, speakers, and Biodex chair. The system acquires torque data from a six-degree-of-freedom load cell. The acquired data, in conjunction with a biomechanical model, indicate the extent to which the participant flexes about the testing elbow and abducts about the shoulder. In addition, the system quantifies muscle activity using eight surface electromyography (sEMG) electrodes (sEMG1: biceps, sEMG2: triceps lateral, sEMG3: anterior deltoid, sEMG4: medial deltoid, sEMG5: posterior deltoid, sEMG6: pectoralis major, sEMG7: lower trapezius, and sEMG8: middle trapezius). The sEMG signals indicate the electrical activity within each of the eight testing muscles. A DAQ card acquires data from these sensors, and a Matlab program streams the data. Data is collected at 1kHz.

#### n Sum
<img src="src/image/readme/setup.png" width="850">

The participant was requested to not exercise the day before and of testing to avoid muscle fatigue. At the beginning of the testing session, the participant sat with their torso and waist strapped to the Biodex chair. The participant's testing arm was affixed to an isometric measurement device at 85° shoulder abduction, 40° shoulder flexion, and 90° elbow flexion.


