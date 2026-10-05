# Reverse Linked List

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 5, 2026 |
| **Tags** | Linked List, Recursion |
| **Link** | [View Problem](https://leetcode.com/problems/reverse-linked-list/) |
| **Runtime** | 0 ms |
| **Memory** | 13.3 MB |

## Problem Description

<p>Given the <code>head</code> of a singly linked list, reverse the list, and return <em>the reversed list</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [5,4,3,2,1]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg" style="width: 182px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2]
<strong>Output:</strong> [2,1]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is the range <code>[0, 5000]</code>.</li>
	<li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> A linked list can be reversed either iteratively or recursively. Could you implement both?</p>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: [C++] Iterative vs. Recursive Solutions Compared and Explained, ~99% Time, ~85% Space
**Author**: [@Ajna](https://leetcode.com/Ajna/)
**Upvotes**: 1008 👍
**Link**: [View Original Post](https://leetcode.com/problems/reverse-linked-list/solutions/803955/)

---

Not sure how this problem is expecting me to use less memory than this, but here is the deal:
* we are going to use 3 variables: `prevNode`, `head` and `nextNode`, that you can easily guess what are meant to represent as we go;
* we will initialise `prevNode` to `NULL`, while `nextNode` can stay empty;
* we are then going to loop until our current main iterator (`head`) is truthy (ie: not `NULL`), which would imply we reached the end of the list;
* during the iteration, we first of all update `nextNode` so that it acquires its namesake value, the one of the next node indeed: `head->next`;
* we then proceeding "reversing" `head->next` and assigning it the value of `prevNode`, while `prevNode` will become take the current value of `head`;
* finally, we update `head` with the value we stored in `nextNode` and go on with the loop until we can. After the loop, we return `prevNode`.

I know it is complex, but I find this gif from another platform to make the whole logic much easier to understand (bear in mind we do not need `curr` and will just use `head` in its place):

![reverting a list](https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif)

The code:

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
};
```

Relatively trivial refactor (the function does basically the same) with recursion and comma operator to make it one-line:

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode *head, ListNode *nextNode = NULL, ListNode *prevNode = NULL) {
        return head ? reverseList(head->next, (head->next = prevNode, nextNode), head) : prevNode;
    }
};
```

</details>
