# Knowledge
- [Big 0](#big-o) 
  - [Time Complexity](#time-complexity)
  - [Space Complexity Complexity](#space-complexity)

- [Merge Sort](#merge-sort)(先局部有序 再整体有序)
- [Four Sum](#four-sum)
- [nSum](#n-sum)


### Big 0
- For very large input size
- For worst case scenario
#### Time Complexity
:star: Drop lower order terms<br>
:star: Drop all the constant multipliers

1.  Sequential Statements:
    
    


#### Space Complexity
3 steps: Divide, Conquer, Combine

Divide: 
<img src="image/merge_sort_merge.png" width="550"><br>
Combine:
<img src="image/merge_sort_split.png" width="550">

Time Complexity: O(nlogn) + O(n) = O(nlogn) <br>
Space complexity: O(n)<br>
It's much stable compared with quick sort

