# Knowledge
- [Big O](#big-o) 
  - [Time Complexity](#time-complexity)
  - [Space Complexity](#space-complexity)

- [Merge Sort](#merge-sort)(先局部有序 再整体有序)
- [Four Sum](#four-sum)
- [nSum](#n-sum)


### Big 0
- For very large input size
- For worst case scenario
#### Time Complexity
<img src="image/timeo.png" width="550"><br>
:star: Drop lower order terms<br>
:star: Drop all the constant multipliers

1. Sequential Statements:
    * a = a + b //constant time: c<sub>1</sub>
    * **Loop:** for (i = 1; i < n; i++) {
        x = y + z; }   //c<sub>2</sub>n
    * **Nested Loop：** for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
        x = y + z; } } // c<sub>3</sub>n<sup>2</sup>
    * overall: c1 + c<sub>2</sub>n + c<sub>3</sub>n<sup>2</sup> -> O(n<sup>2</sup>)
2. Binary Search: T(N) = T(N/2) + c(constant time for check)
    * T(N/2) = T(N/4) + c -> T(N) = T(N/4) + 2c -> T(N) = T(N/2<sup>i</sup>) + ic
    * **At some point, as N/2^i diminishes, we reach only 1 element:** T(N/2^i) = T(1)-> N = 2<sup>i</sup> -> i = log N
    * T(N) = T(1) + clog N -> log N
    
3. Quick Sort / Merge Sort: T(n) = 2T(n/2) + O(n)
    * T(n/2) = 2T(n/4) + O(n/2) -> T(n) = 4T(n/4) + 2O(n) -> T(n) = 2<sup>i</sup>T(n/2<sup>i</sup>) + 2<sup>i</sup>O(n)
    * i = log n
    * T(n) = O(n) + O(nlogn) = O(nlogn)

-> Time complexity for sorting algorithms:
<img src="image/sort.png" width="550"><br>



#### Space Complexity
3 steps: Divide, Conquer, Combine

Divide: 
<img src="image/merge_sort_merge.png" width="550"><br>
Combine:
<img src="image/merge_sort_split.png" width="550">

Time Complexity: O(nlogn) + O(n) = O(nlogn) <br>
Space complexity: O(n)<br>
It's much stable compared with quick sort

