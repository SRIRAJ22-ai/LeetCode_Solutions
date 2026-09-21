# Count Elements With Maximum Frequency

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | September 21, 2026 |
| **Tags** | Array, Hash Table, Counting |
| **Link** | [View Problem](https://leetcode.com/problems/count-elements-with-maximum-frequency/) |
| **Runtime** | 0 ms |
| **Memory** | 23 MB |

## Problem Description

<p>You are given an array <code>nums</code> consisting of <strong>positive</strong> integers.</p>

<p>Return <em>the <strong>total frequencies</strong> of elements in</em><em> </em><code>nums</code>&nbsp;<em>such that those elements all have the <strong>maximum</strong> frequency</em>.</p>

<p>The <strong>frequency</strong> of an element is the number of occurrences of that element in the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,2,3,1,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> 5
<strong>Explanation:</strong> All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 🔥✅✅ Beat 83.69% | ✅ Full explanation with pictures ✅✅🔥
**Author**: [@DevOgabek](https://leetcode.com/DevOgabek/)
**Upvotes**: 77 👍
**Link**: [View Original Post](https://leetcode.com/problems/count-elements-with-maximum-frequency/solutions/4839796/)

---


[![Screen Shot 2024-03-08 at 05.13.54.png](https://assets.leetcode.com/users/images/a92db811-9780-4ea3-9753-fc1f360b2023_1709856870.8436275.png)](https://leetcode.com/problems/count-elements-with-maximum-frequency/submissions/1197139735)

![Glenn Radars_4 3.png](https://assets.leetcode.com/users/images/61cac30a-24af-4592-8f15-e03d98768f32_1709600028.6615255.png)

![Glenn Radars_9 2 4.png](https://assets.leetcode.com/users/images/0866f462-3500-43da-950a-5c1e0c48d97b_1709600960.6204474.png)

![0d553654-43de-4762-97f7-2d2a9387018f_1709773744.056001 2.png](https://assets.leetcode.com/users/images/8fb76fa4-9dbb-46dc-99bc-9af18f5ca4e7_1709857778.7426538.png)

![0d553654-43de-4762-97f7-2d2a9387018f_1709773744.056001 2.png](https://assets.leetcode.com/users/images/e86cca40-d890-46da-b28c-869aa3ddbf4b_1709858026.3644254.png)

![0d553654-43de-4762-97f7-2d2a9387018f_1709773744.056001 2.png](https://assets.leetcode.com/users/images/3fb98598-9470-4111-a5fd-706aad769dae_1709858095.1089835.png)


![0d553654-43de-4762-97f7-2d2a9387018f_1709773744.056001 2.png](https://assets.leetcode.com/users/images/76a83140-1318-4aa5-8374-3ca073664df2_1709858474.8832865.png)


![0d553654-43de-4762-97f7-2d2a9387018f_1709773744.056001 2.png](https://assets.leetcode.com/users/images/fc315f32-c7e1-443d-b3fd-c92ee7e7880f_1709858731.8370585.png)


```python []
class Solution(object):
    def maxFrequencyElements(self, nums):
        freq_counter = Counter(nums)
        
        max_frequency = max(freq_counter.values())

        max_freq_elements = [num for num, freq in freq_counter.items() if freq == max_frequency]

        total_frequency = max_frequency * len(max_freq_elements)

        return total_frequency
```
```python3 []
class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq_counter = Counter(nums)
        
        max_frequency = max(freq_counter.values())
        
        max_freq_elements = [num for num, freq in freq_counter.items() if freq == max_frequency]
        
        total_frequency = max_frequency * len(max_freq_elements)
        
        return total_frequency
```
```C++ []
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        std::unordered_map<int, int> freqCounter;
        for (int num : nums) {
            freqCounter[num]++;
        }

        int maxFrequency = 0;
        for (const auto& entry : freqCounter) {
            maxFrequency = std::max(maxFrequency, entry.second);
        }

        int maxFreqElements = 0;
        for (const auto& entry : freqCounter) {
            if (entry.second == maxFrequency) {
                maxFreqElements++;
            }
        }

        int totalFrequency = maxFrequency * maxFreqElements;

        return totalFrequency;
    }
};
```

```javascript []
var maxFrequencyElements = function(nums) {
    const freqCounter = new Map();
    for (const num of nums) {
        freqCounter.set(num, (freqCounter.get(num) || 0) + 1);
    }

    const maxFrequency = Math.max(...freqCounter.values());

    const maxFreqElements = [...freqCounter.keys()].filter(num => freqCounter.get(num) === maxFrequency);

    const totalFrequency = maxFrequency * maxFreqElements.length;

    return totalFrequency;
};
```

![Glenn Radars_9 2 4 2.png](https://assets.leetcode.com/users/images/c2c8fe57-160f-42c0-a57a-a543d9ca335a_1709601428.5689478.png)

## **My solutions**

\uD83D\uDFE2 - $$easy$$  
\uD83D\uDFE1 - $$medium$$ 
\uD83D\uDD34 - $$hard$$

\uD83D\uDFE1 [17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/solutions/4845532/there-is-an-80-chance-of-being-in-the-interview-full-problem-explanation)
\uD83D\uDFE1 [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/solutions/4845742/simple-explanation-with-pictures)
\uD83D\uDFE1 [39. Combination Sum](https://leetcode.com/problems/combination-sum/solutions/4847482/beat-8292-full-explanation-with-pictures)
\uD83D\uDFE2 [2540. Minimum Common Value](https://leetcode.com/problems/minimum-common-value/solutions/4845076/beat-9759-full-explanation-with-pictures)
\uD83D\uDFE2 [3005. Count Elements With Maximum Frequency](https://leetcode.com/problems/count-elements-with-maximum-frequency/solutions/4839796/beat-8369-full-explanation-with-pictures)
\uD83D\uDFE2 [3028. Ant on the Boundary](https://leetcode.com/problems/ant-on-the-boundary/solutions/4837433/full-explanation-with-pictures)
\uD83D\uDFE2 [876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/solutions/4834682/beat-10000-full-explanation-with-pictures)
\uD83D\uDFE1 [1750. Minimum Length of String After Deleting Similar Ends](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/solutions/4824224/beat-10000-full-explanation-with-pictures)
\uD83D\uDFE1 [948. Bag of Tokens](https://leetcode.com/problems/bag-of-tokens/solutions/4818912/beat-10000-full-explanation-with-pictures)
\uD83D\uDFE1 [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/4813340/beat-10000-full-explanation-with-pictures)
\uD83D\uDFE2 [977. Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/solutions/4807704/square-sorter-python-python3-javascript-c)
\uD83D\uDFE2 [2864. Maximum Odd Binary Number](https://leetcode.com/problems/maximum-odd-binary-number/solutions/4802402/visual-max-odd-binary-solver-python-python3-javascript-c)
\uD83D\uDFE1 [1609. Even Odd Tree](https://leetcode.com/problems/even-odd-tree/solutions/4797529/even-odd-tree-validator-python-python3-javascript-c)
\uD83D\uDFE2 [9. Palindrome Number](https://leetcode.com/problems/palindrome-number/solutions/4795373/why-not-1-line-of-code-python-python3-c-everyone-can-understand)
\uD83D\uDFE1 [513. Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/solutions/4792022/binary-tree-explorer-mastered-javascript-python-python3-c-10000-efficiency-seeker)
\uD83D\uDFE2 [1. Two Sum](https://leetcode.com/problems/two-sum/solutions/4791305/5-methods-python-c-python3-from-easy-to-difficult)
\uD83D\uDFE2 [543. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/solutions/4787634/surpassing-9793-memory-magician-excelling-at-9723)
[More...](https://leetcode.com/DevOgabek/)


</details>
