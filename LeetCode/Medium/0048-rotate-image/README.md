<h2><a href="https://leetcode.com/problems/rotate-image">48. Rotate Image</a></h2><h3>Medium</h3><hr><p>You are given an <code>n x n</code> 2D <code>matrix</code> representing an image, rotate the image by <strong>90</strong> degrees (clockwise).</p>

<p>You have to rotate the image <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank"><strong>in-place</strong></a>, which means you have to modify the input 2D matrix directly. <strong>DO NOT</strong> allocate another 2D matrix and do the rotation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg" style="width: 500px; height: 188px;" />
<pre>
<strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [[7,4,1],[8,5,2],[9,6,3]]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg" style="width: 500px; height: 201px;" />
<pre>
<strong>Input:</strong> matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
<strong>Output:</strong> [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>-1000 &lt;= matrix[i][j] &lt;= 1000</code></li>
</ul>


# The Origami of Matrices: Folding 90 Degrees

### The Memory Paradox
I looked at the $n \times n$ grid and realized that a 90° rotation is essentially a coordinate remapping. Usually, you'd just create a new grid and map $(r, c)$ to $(c, n-1-r)$. But the constraint was strict: **In-place.** This changed the problem from a simple mapping to a memory puzzle. If I move a pixel to its new spot, I overwrite the data that lived there. I needed to find a sequence of moves that wouldn't destroy the information before it was used.

### The Reflection Insight
Think of the matrix not as a static block of numbers, but as a square sheet of paper. Rotating a paper 90 degrees in 3D space is one motion, but on a 2D plane with memory constraints, we have to "fold" it. 

I identified that a rotation is just a composite of two simpler reflections:
1. **The Transpose Fold:** Flip the matrix over its main diagonal (from top-left to bottom-right). Suddenly, every row becomes a column. The data is in the right "slots," but it's a mirror image of what we want.
2. **The Mirror Correction:** To fix the mirror effect, we flip each row horizontally. 

By performing these two specific "folds," we arrive at a 90° clockwise rotation without ever needing a second sheet of paper.

### The Pipeline
*   **What goes in:** A square $n \times n$ tensor (image matrix).
*   **How it transforms:** We swap elements across the diagonal axis $i=j$, then reverse the sequence of each individual row.
*   **What comes out:** The same memory block, now oriented 90° clockwise.

### The Implementations

#### Idiomatic Python
In Python, we leverage tuple unpacking for the transpose and the built-in `reverse()` for the horizontal flip. This is clean and matches how we handle tensors in ML pipelines.

```python
class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        n = len(matrix)
        
        # Phase 1: Transpose - Rows become Columns
        for i in range(n):
            # We start from i + 1 to avoid swapping back to original
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        # Phase 2: Horizontal Flip
        for row in matrix:
            row.reverse()
```

#### Memory-Efficient C++
In C++, we focus on the efficiency of `std::swap`. Using `auto&` in the row reversal ensures we are modifying the actual memory inside the vector, not a copy.

```cpp
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Phase 1: Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Phase 2: Reverse each row using iterators
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};
```

### The Cost
*   **Time Complexity:** $O(n^2)$. We touch each element twice (once to transpose, once to reverse), but in Big O, constants fall away.
*   **Space Complexity:** $O(1)$. We performed the entire operation within the existing memory footprint of the matrix.

---
