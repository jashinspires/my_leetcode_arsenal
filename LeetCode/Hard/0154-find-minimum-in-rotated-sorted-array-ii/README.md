<h2><a href="https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii">154. Find Minimum in Rotated Sorted Array II</a></h2><h3>Hard</h3><hr><p>Suppose an array of length <code>n</code> sorted in ascending order is <strong>rotated</strong> between <code>1</code> and <code>n</code> times. For example, the array <code>nums = [0,1,4,4,5,6,7]</code> might become:</p>

<ul>
	<li><code>[4,5,6,7,0,1,4]</code> if it was rotated <code>4</code> times.</li>
	<li><code>[0,1,4,4,5,6,7]</code> if it was rotated <code>7</code> times.</li>
</ul>

<p>Notice that <strong>rotating</strong> an array <code>[a[0], a[1], a[2], ..., a[n-1]]</code> 1 time results in the array <code>[a[n-1], a[0], a[1], a[2], ..., a[n-2]]</code>.</p>

<p>Given the sorted rotated array <code>nums</code> that may contain <strong>duplicates</strong>, return <em>the minimum element of this array</em>.</p>

<p>You must decrease the overall operation steps as much as possible.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,5]
<strong>Output:</strong> 1
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,2,2,0,1]
<strong>Output:</strong> 0
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>-5000 &lt;= nums[i] &lt;= 5000</code></li>
	<li><code>nums</code> is sorted and rotated between <code>1</code> and <code>n</code> times.</li>
</ul>



<p>&nbsp;</p>
<p><strong>Follow up:</strong> This problem is similar to&nbsp;<a href="https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/" target="_blank">Find Minimum in Rotated Sorted Array</a>, but&nbsp;<code>nums</code> may contain <strong>duplicates</strong>. Would this affect the runtime complexity? How and why?</p>

<p>&nbsp;</p>


# Find Minimum in Rotated Sorted Array II

## The Challenge

At first glance, finding the minimum element in an array seems like a trivial $O(n)$ problem - just loop through and keep track of the smallest number. However, this project implements an optimized approach using **Binary Search** to find the minimum element in a sorted array that has been rotated an unknown number of times and **contains duplicates**.

The presence of duplicates elevates this problem to a "Hard" classification because identical elements can obscure the direction the binary search needs to take.

---

## How I Solved It: The Intuition

In a standard rotated sorted array (without duplicates), we can easily decide which half to discard by comparing the middle element (`mid`) with the rightmost element (`high`).

With duplicates, we encounter a unique edge case where `nums[low] == nums[mid] == nums[high]`. When this happens, the algorithm cannot determine if the minimum element lies to the left or the right of `mid`.

To solve this, I designed a modified binary search with a three-way conditional strategy:

1. **`nums[mid] > nums[high]`**: This tells us that the inflection point (and the minimum element) must lie to the **right** of `mid`. We shift our lower bound: `low = mid + 1`.
2. **`nums[mid] < nums[high]`**: This indicates that the right half is properly sorted, meaning `mid` itself could be the minimum, or the minimum is to its **left**. We adjust our upper bound: `high = mid`.
3. **`nums[mid] == nums[high]`**: This is the duplicate trap. Since we can't safely jump halves, we cautiously shrink our search space by decrementing the right pointer: `high--`. This preserves the minimum element while breaking the tie.

---

## Complexity Analysis

* **Time Complexity:**
* **Average Case:** $O(\log n)$ when duplicates are sparse, allowing the binary search to halve the search space effectively.
* **Worst Case:** $O(n)$ when the array is heavily populated with duplicates (e.g., `[2, 2, 2, 0, 2]`). The algorithm safely degrades to a linear reduction (`high--`) to avoid missing the target.


* **Space Complexity:** $O(1)$ as the search is performed entirely in-place without allocating extra memory.

---

## The Code

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                high = mid;
            } else {
                high--;
            }
        }
        
        return nums[low];
    }
};

```
