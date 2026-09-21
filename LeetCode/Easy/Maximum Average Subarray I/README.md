# Maximum Average Subarray I

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | September 21, 2026 |
| **Tags** | Array, Sliding Window |
| **Link** | [View Problem](https://leetcode.com/problems/maximum-average-subarray-i/) |
| **Runtime** | 6 ms |
| **Memory** | 113.8 MB |

## Problem Description

<p>You are given an integer array <code>nums</code> consisting of <code>n</code> elements, and an integer <code>k</code>.</p>

<p>Find a contiguous subarray whose <strong>length is equal to</strong> <code>k</code> that has the maximum average value and return <em>this value</em>. Any answer with a calculation error less than <code>10<sup>-5</sup></code> will be accepted.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,12,-5,-6,50,3], k = 4
<strong>Output:</strong> 12.75000
<strong>Explanation:</strong> Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5], k = 1
<strong>Output:</strong> 5.00000
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Py3 | Beginner friendly with details and explanation
**Author**: [@younus_baig](https://leetcode.com/younus_baig/)
**Upvotes**: 182 👍
**Link**: [View Original Post](https://leetcode.com/problems/maximum-average-subarray-i/solutions/3532127/)

---

# Approach

This problem uses sliding window concept.
You can solve this problem using two loops in $O(n^2)$ time complexity. However, with sliding window approach, you can easily resolve this in O(n) time.


Follow the images below to look at how this works:
1. Our given input
![Given input nums and k value](https://assets.leetcode.com/users/images/ff3c3f0c-58ef-4cdd-8054-02a131ead1e5_1684267087.7711663.png)
2. Initialization
![This image expplains sliding window concept and our initial values](https://assets.leetcode.com/users/images/eb84364e-2548-420c-a408-3f6d80f252e0_1684267239.3961222.png)

3. Operations
![This image shows the sliding of the window and how we perform those operations](https://assets.leetcode.com/users/images/8e88d87e-35cf-426d-b7a3-aa1c71e8d166_1689524170.455872.png)

3. Final operation
![This image shows the final step of the problems](https://assets.leetcode.com/users/images/9c436e6e-ee49-4ead-8f04-13f50f7b78cf_1684267145.8853574.png)
4. We now return the `maxSum / k` to return the max average.

# Complexity
 Time: O(n)
Space: O(1)

# Code
``` Python []
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        
        # Initialize currSum and maxSum to the sum of the initial k elements
        currSum = maxSum = sum(nums[:k])

        # Start the loop from the kth element 
        # Iterate until you reach the end
        for i in range(k, len(nums)):

            # Subtract the left element of the window
            # Add the right element of the window
            currSum += nums[i] - nums[i - k]
            
            # Update the max
            maxSum = max(maxSum, currSum)

        # Since the problem requires average, we return the average
        return maxSum / k

```
``` C++ []
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0, maxSum = 0;
        
        // Initialize currSum and maxSum to the sum of the initial k elements
        for (int i = 0; i < k; i++)
            currSum += nums[i];
        maxSum = currSum;
        
        // Start the loop from the kth element 
        // Iterate until you reach the end
        for (int i = k; i < nums.size(); i++) {
            // Subtract the left element of the window
            // Add the right element of the window
            currSum += nums[i] - nums[i - k];
            
            // Update the max
            maxSum = max(maxSum, currSum);
        }
        
        // Since the problem requires average, we return the average
        return maxSum / k;
    }
};

```

</details>
