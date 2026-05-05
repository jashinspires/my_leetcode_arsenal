<h2><a href="https://leetcode.com/problems/rotate-list">61. Rotate List</a></h2><h3>Medium</h3><hr><p>Given the <code>head</code> of a linked&nbsp;list, rotate the list to the right by <code>k</code> places.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg" style="width: 450px; height: 191px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [4,5,1,2,3]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg" style="width: 305px; height: 350px;" />
<pre>
<strong>Input:</strong> head = [0,1,2], k = 4
<strong>Output:</strong> [2,0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 500]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>9</sup></code></li>
</ul>
This version is written from the perspective of a developer working through the logic. It explains *why* you wrote each line and the specific "physics" of the linked list you had to respect.

---

#  My Logical Walkthrough for "Rotate List"

### Phase 1: The Preliminary Safety Checks
Before doing any heavy lifting, I had to think about when the problem is already solved for me. I realized that if the list is empty, only has one node, or if I’m asked to rotate 0 times, the answer is just the original list.

```cpp
if(head == nullptr || head->next == nullptr || k == 0){
    return head;
}
```
*   **Depth Check:** Why `head->next == nullptr`? Because you can't rotate a single node; it always points to itself or `nullptr`.

---

### Phase 2: Counting and Finding the Boundary
Since I don't have an `array.length` property, I have to find the length manually. I started my counter `n` at 1 because if I'm at the `head`, I've already "found" the first node.

```cpp
int n = 1; 
ListNode* tail = head;
while(tail->next != nullptr){
    tail = tail->next;
    n++;
}
```
By the time this loop finishes, `tail` isn't just a variable - it’s a physical pointer sitting on the very last node of the list. This is my "hook" to turn the list into a circle.



---

### Phase 3: Creating the Circular "Ring"
This was the most efficient move. Instead of trying to "shift" nodes, I connected the end back to the beginning. 

```cpp
tail->next = head; 
```
Now, I no longer have a start or an end—I have a loop. This allows me to "cut" the list anywhere to create a new starting point.

---

### Phase 4: The Math of the "Cut Point"
This was the trickiest part to visualize. If I rotate $k$ times to the right, I need to find out where the new "back of the line" (the tail) will be.

```cpp
int total_cuts = n - (k % n);
```
*   **Deep Logic:** If the list is 5 nodes long and I rotate 2 times, the new tail should be the 3rd node ($5 - 2 = 3$). 
*   I used `k % n` because if $k$ is 102 and $n$ is 5, rotating 102 times is the exact same as rotating 2 times. It prevents the code from running in circles unnecessarily.

---

### Phase 5: Finding the New Tail
I started a new pointer at the `head` and moved it until it reached the `total_cuts` position.

```cpp
ListNode* newtail = head;
for(int i = 1; i < total_cuts; i++){
    newtail = newtail->next;
}
```
*   **Observation:** I used `i = 1` and `i < total_cuts` because I’m already standing on node 1. To get to node 3, I only need to take 2 steps forward.

---

### Phase 6: The "Surgical" Split
Finally, I had to define the new head and sever the circular connection.

```cpp
ListNode* Newhead = newtail->next; // The node after the tail is the new start
newtail->next = nullptr;           // Break the loop here
return Newhead;
```
*   **The Logic:** `Newhead` catches the node that should be at the front. By setting `newtail->next` to `nullptr`, I turn the circle back into a straight line. The "tail" I found becomes the new end of the list.

---

### Key Summary of the Approach
1.  **Don't Move Nodes:** Don't try to physically move data. Just change the "next" pointers.
2.  **Circular Logic:** Turning a linear list into a circle makes "rotation" just a matter of choosing a new breaking point.
3.  **Pointer Precision:** In a linked list, if you lose the pointer to the `head`, you lose the whole list. I made sure `Newhead` was safely stored before I broke the `nullptr` connection.
