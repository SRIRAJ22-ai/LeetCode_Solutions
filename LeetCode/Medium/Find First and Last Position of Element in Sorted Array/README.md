# Find First and Last Position of Element in Sorted Array

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 17, 2026 |
| **Tags** | Array, Binary Search |
| **Link** | [View Problem](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) |
| **Runtime** | 0 ms |
| **Memory** | 17.6 MB |

## Problem Description

<p>Given an array of integers <code>nums</code> sorted in non-decreasing order, find the starting and ending position of a given <code>target</code> value.</p>

<p>If <code>target</code> is not found in the array, return <code>[-1, -1]</code>.</p>

<p>You must&nbsp;write an algorithm with&nbsp;<code>O(log n)</code> runtime complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 8
<strong>Output:</strong> [3,4]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 6
<strong>Output:</strong> [-1,-1]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [], target = 0
<strong>Output:</strong> [-1,-1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code> is a non-decreasing array.</li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= target&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅☑️ Best C++ 2 Solution || Binary Search || Linear Search || Brute Force->Optimize || One Stop Solu.
**Author**: [@its_vishal_7575](https://leetcode.com/its_vishal_7575/)
**Upvotes**: 398 👍
**Link**: [View Original Post](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/solutions/3188625/)

---

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
We can Solved this question using Two approach. (Here I have explained all the possible solutions of this problem).

1. Solved using Linear Search (Brute Force Approach).
2. Solved using Binary Search (Optimized Approach).

# Approach
<!-- Describe your approach to solving the problem. -->
We can easily understand the All the approaches by seeing the code which is easy to understand with comments.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
Time complexity is given in code comment.

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
Space complexity is given in code comment.

# Code
```
/*

    Time Complexity : O(N), because in the worst case we traverse the <= N element. Where N is the size of the
    Array(nums).
                    
    Space Complexity : O(1), the space complexity is constant.

    Solved using Linear Search.

*/


/***************************************** Approach 1 First Code *****************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startingPosition = -1, endingPosition = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                startingPosition = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] == target){
                endingPosition = i;
                break;
            }
        }
        return {startingPosition, endingPosition};
    }
};






/*

    Time Complexity : O(log N), since we have used binary search to find the target element. The time complexity
    is logarithmic.

    Space Complexity : O(1), since we stored only some constant number of elements, the space complexity is
    constant.

    Solved using Binary Search.

*/


/***************************************** Approach 2 First Code *****************************************/

class Solution {
private:
    int lower_bound(vector<int>& nums, int low, int high, int target){
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int startingPosition = lower_bound(nums, low, high, target);
        int endingPosition = lower_bound(nums, low, high, target + 1) - 1;
        if(startingPosition < nums.size() && nums[startingPosition] == target){
            return {startingPosition, endingPosition};
        }
        return {-1, -1};
    }
};






/***************************************** Approach 2 Second Code *****************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startingPosition = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int endingPosition = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin() - 1;
        if(startingPosition < nums.size() && nums[startingPosition] == target){
            return {startingPosition, endingPosition};
        }
        return {-1, -1};
    }
};

```

***IF YOU LIKE THE SOLUTION THEN PLEASE UPVOTE MY SOLUTION BECAUSE IT GIVES ME MOTIVATION TO REGULARLY POST THE SOLUTION.***

![WhatsApp Image 2023-02-10 at 19.01.02.jpeg](https://assets.leetcode.com/users/images/0a95fea4-64f4-4502-82aa-41db6d77c05c_1676054939.8270252.jpeg)

</details>
