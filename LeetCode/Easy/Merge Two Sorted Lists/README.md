# Merge Two Sorted Lists

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 5, 2026 |
| **Tags** | Linked List, Recursion |
| **Link** | [View Problem](https://leetcode.com/problems/merge-two-sorted-lists/) |
| **Runtime** | 0 ms |
| **Memory** | 19.5 MB |

## Problem Description

<p>You are given the heads of two sorted linked lists <code>list1</code> and <code>list2</code>.</p>

<p>Merge the two lists into one <strong>sorted</strong> list. The list should be made by splicing together the nodes of the first two lists.</p>

<p>Return <em>the head of the merged linked list</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg" style="width: 662px; height: 302px;">
<pre><strong>Input:</strong> list1 = [1,2,4], list2 = [1,3,4]
<strong>Output:</strong> [1,1,2,3,4,4]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> list1 = [], list2 = []
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> list1 = [], list2 = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in both lists is in the range <code>[0, 50]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li>Both <code>list1</code> and <code>list2</code> are sorted in <strong>non-decreasing</strong> order.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 3 lines C++ (12ms) and C (4ms)
**Author**: [@StefanPochmann](https://leetcode.com/StefanPochmann/)
**Upvotes**: 111 👍
**Link**: [View Original Post](https://leetcode.com/problems/merge-two-sorted-lists/solutions/9814/)

---

**C++**

The first line ensures that `a` is at least as good a list head as `b`, by swapping them if that's not already the case. The second line merges the remaining lists behind `a`.

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (!a || b && a->val > b->val) swap(a, b);
        if (a) a->next = mergeTwoLists(a->next, b);
        return a;
    }

---

**C**

Same solution, I just have to replace C++'s `swap`. I'm not sure whether evaluation order is standardized, but it worked and got accepted this way.

    struct ListNode* mergeTwoLists(struct ListNode* a, struct ListNode* b) {
        if (!a || b && a->val > b->val) a += b - (b = a);
        if (a) a->next = mergeTwoLists(a->next, b);
        return a;
    }

</details>
