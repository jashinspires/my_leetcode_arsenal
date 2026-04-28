<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid">2160. Minimum Operations to Make a Uni-Value Grid</a></h2><h3>Medium</h3><hr><p>You are given a 2D integer <code>grid</code> of size <code>m x n</code> and an integer <code>x</code>. In one operation, you can <strong>add</strong> <code>x</code> to or <strong>subtract</strong> <code>x</code> from any element in the <code>grid</code>.</p>

<p>A <strong>uni-value grid</strong> is a grid where all the elements of it are equal.</p>

<p>Return <em>the <strong>minimum</strong> number of operations to make the grid <strong>uni-value</strong></em>. If it is not possible, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt.png" style="width: 164px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[2,4],[6,8]], x = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt-1.png" style="width: 164px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[1,5],[2,3]], x = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> We can make every element equal to 3.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/21/gridtxt-2.png" style="width: 164px; height: 165px;" />
<pre>
<strong>Input:</strong> grid = [[1,2],[3,4]], x = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is impossible to make every element equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x, grid[i][j] &lt;= 10<sup>4</sup></code></li>
</ul>


# The Geometry of the Grid: How I Solved this...

When I first looked at this problem, I saw a grid and a "leap size" $x$. My task was to make every element equal using the minimum number of operations. But as I dove deeper, I realized this wasn't a grid problem at all—it was a problem about **synchronization** and **balance**.

## Part 1: The "Out of Phase" Realization
The first thing I had to ask myself was: *Can these numbers even meet?* If $x=5$, and I have one number at **12** and another at **14**, they are fundamentally broken. 
* 12 can become 7, 2, 17, 22... (It always ends in 2 or 7).
* 14 can become 9, 4, 19, 24... (It always ends in 4 or 9).

No matter how many times I add or subtract 5, they will never intersect. They are moving on parallel tracks. 

**The Insight:** Every number in the grid must share the same "phase." Mathematically, they must all have the same remainder when divided by $x$. If I find even one number that doesn't match the first one's remainder, I know the task is impossible and I return `-1`.



## Part 2: Finding the "Sweet Spot" (Tug-of-War)
Once I knew they *could* meet, I needed to find the optimal meeting point. My first instinct was to look at the average, but I caught myself. The average minimizes *squared* distances. But here, the cost of moving a number is linear—it’s just the number of leaps.

I imagined a tug-of-war. If I have people standing at 10, 20, and 100:
* If I stand at the **Average** (~43), the person at 100 pulls me toward them, but I'm moving very far away from the people at 10 and 20. 
* If I stand at the **Median** (20), the number of people to my left is balanced by the number of people to my right. 

In a linear world, the **Median** is the point of minimum total movement. Every step I move away from the median to the right makes the people on the left travel further, and the math just doesn't favor it.



## Part 3: My Implementation Strategy
I broke the process down into a simple pipeline:
1.  **Flatten the World:** I turned the 2D grid into a 1D list. It’s easier to visualize a single road than a map.
2.  **Verify the Phase:** Before doing any heavy lifting, I checked if everyone shared that common remainder.
3.  **Sort for the Median:** To find the middle, I had to bring order to the chaos. Sorting let me pick the exact median index.
4.  **Count the Leaps:** Finally, I just summed up how many "steps of $x$" every number needed to reach that median.

---

## The Code

### Python
I used a list comprehension for a clean flattening process and then a simple loop to calculate the cost.

```python
class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        # 1. Flatten the grid
        nums = [val for row in grid for val in row]
        
        # 2. Check the "Phase"
        target_mod = nums[0] % x
        for n in nums:
            if n % x != target_mod:
                return -1
        
        # 3. Find the Median
        nums.sort()
        median = nums[len(nums) // 2]
        
        # 4. Sum the total leaps
        return sum(abs(n - median) // x for n in nums)
```

### C++
In C++, I focused on memory efficiency. I used `reserve()` to prevent the vector from constantly re-allocating memory as I flattened the grid.

```cpp
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> nums;
        nums.reserve(m * n); // Pre-allocate for speed

        int startMod = grid[0][0] % x;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != startMod) return -1;
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());
        
        int median = nums[nums.size() / 2];
        int totalOps = 0;

        for (int val : nums) {
            totalOps += abs(val - median) / x;
        }

        return totalOps;
    }
};
```

---

### Final Thoughts on Complexity
* **Time:** $O(N \log N)$ because I had to sort the elements to find the median.
* **Space:** $O(N)$ because I needed a separate array to perform the sort.

---
