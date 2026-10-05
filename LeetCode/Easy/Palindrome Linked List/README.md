# Palindrome Linked List

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 5, 2026 |
| **Tags** | Linked List, Two Pointers, Stack, Recursion |
| **Link** | [View Problem](https://leetcode.com/problems/palindrome-linked-list/) |
| **Runtime** | 3 ms |
| **Memory** | 117.9 MB |

## Problem Description

<p>Given the <code>head</code> of a singly linked list, return <code>true</code><em> if it is a </em><span data-keyword="palindrome-sequence" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_t_" data-state="closed" class=""><em>palindrome</em></button></span><em> or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg" style="width: 422px; height: 62px;">
<pre><strong>Input:</strong> head = [1,2,2,1]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg" style="width: 182px; height: 62px;">
<pre><strong>Input:</strong> head = [1,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you do it in <code>O(n)</code> time and <code>O(1)</code> space?

##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 3 Approaches (Step by Step) || don't need any other solution after watching this🤞
**Author**: [@Srajan_Agrawal](https://leetcode.com/Srajan_Agrawal/)
**Upvotes**: 528 👍
**Link**: [View Original Post](https://leetcode.com/problems/palindrome-linked-list/solutions/3307045/)

---

# Check if the linked list is palindrome or not.

Honestly Speakaing (Maja aa gya)
I solved this problem first time without using any reference just by finding the different ways to solve it.
At the first I thought like palindrome hii to check krna hai then just traverse kro aur usko kisi variable main store krke uska reverse lekar check kr lo. Such as
```
if list is
1->2->2->1
then temp = 1221
r_temp = 1221 (temp ka reverse)
and then compare kiya if(temp == r_temp) then
return true
else{
false return krdo
}
```
But But But.................
Any problems find ?
See here the no. of nodes in the linked list can vary from [1,10^5] and there is no way to store these many value in the variable.

It will go out of range of long long int or any other data type then what\'s next?

# Second Approach (Reverse the list)
Here I thought like what if I will reverse the whole list and then compare each and every element then if it is not equal return false otherwise return true.

Here is the code :

# Code
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Some Brute Force Steps to follow
        // 1) Reverse the list and store it in r_head;
        // and then compare head->val and r_head->val if equal move both the pointers otherwise if not equal return false.
        // When the loop will be executed fully retrun true
         if(head == NULL || head->next == NULL){
            return (head);
        }
        ListNode *r_head = NULL;
        ListNode *ptr = head;
        while(ptr!=NULL){
            ListNode *temp = new ListNode(ptr->val);
            temp ->next = r_head;
            r_head = temp;
            ptr = ptr->next;
        }
        while(head && r_head){
            if(head->val != r_head->val){
                return false;
            }
            head = head->next;
            r_head = r_head->next;
        }
        return true;
    }
};
```

# Third Approach (Reverse the end half)
Here I will follow these steps 
- (Base Case) If head == NULL || head->next == NULL Return true;
 ```
if(head == NULL || head->next == NULL){
    return (head);
}
```
- Find the middle element (using two pointers)
- Reverse the end half
- Compare the start and reverse end half (if all equal return true)
- Otherwise return false
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Steps to follow:
        // 1_) Find the middle element
        ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // 2_) if the no of nodes are odd then move slow to one point
        if(fast != NULL && fast->next == NULL){
            slow = slow->next;
        }
        //3_) Reverse the end half
        ListNode *prev = NULL;
        ListNode *temp = NULL;
        while(slow != NULL && slow->next != NULL){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        if(slow != NULL){
            slow->next = prev;
        }
        //4_) Compare the start half and end half if found any inequality then return false otherwise return true.
        fast = head;
        while(slow && fast){
            if(slow->val != fast->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;

    }
};
```
![upvoteCatImage.jpeg](https://assets.leetcode.com/users/images/3815c804-b225-4c1f-b62b-c2af5cfc1a0e_1679045089.4677224.jpeg)

Please Upvote it. It takes a lot of enery and time creating it.


</details>
