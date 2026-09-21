# Range Sum Query - Immutable

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | September 21, 2026 |
| **Tags** | Array, Design, Prefix Sum |
| **Link** | [View Problem](https://leetcode.com/problems/range-sum-query-immutable/) |
| **Runtime** | 7 ms |
| **Memory** | 24.1 MB |

## Problem Description

<p>Given an integer array <code>nums</code>, handle multiple queries of the following type:</p>

<ol>
	<li>Calculate the <strong>sum</strong> of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> <strong>inclusive</strong> where <code>left &lt;= right</code>.</li>
</ol>

<p>Implement the <code>NumArray</code> class:</p>

<ul>
	<li><code>NumArray(int[] nums)</code> Initializes the object with the integer array <code>nums</code>.</li>
	<li><code>int sumRange(int left, int right)</code> Returns the <strong>sum</strong> of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> <strong>inclusive</strong> (i.e. <code>nums[left] + nums[left + 1] + ... + nums[right]</code>).</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
<strong>Output</strong>
[null, 1, -1, -3]

<strong>Explanation</strong>
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= left &lt;= right &lt; nums.length</code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>sumRange</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 5-lines C++, 4-lines Python
**Author**: [@jianchao-li](https://leetcode.com/jianchao-li/)
**Upvotes**: 130 👍
**Link**: [View Original Post](https://leetcode.com/problems/range-sum-query-immutable/solutions/75184/)

---

The idea is fairly straightforward: create an array `accu` that stores the accumulated sum for `nums` such that `accu[i] = nums[0] + ... + nums[i - 1]` in the initializer of `NumArray`. Then just return `accu[j + 1] - accu[i]` in `sumRange`. You may try the example in the problem statement to convince yourself of this idea.

The code is as follows.

----------
**C++**

    class NumArray {
    public:
        NumArray(vector<int> &nums) {
            accu.push_back(0);
            for (int num : nums)
                accu.push_back(accu.back() + num);
        }
    
        int sumRange(int i, int j) {
            return accu[j + 1] - accu[i];
        }
    private:
        vector<int> accu;
    };
    
    
    // Your NumArray object will be instantiated and called as such:
    // NumArray numArray(nums);
    // numArray.sumRange(0, 1);
    // numArray.sumRange(1, 2); 

----------
**Python**

    class NumArray(object):
        def __init__(self, nums):
            """
            initialize your data structure here.
            :type nums: List[int]
            """
            self.accu = [0]
            for num in nums: 
                self.accu += self.accu[-1] + num,
    
        def sumRange(self, i, j):
            """
            sum of elements nums[i..j], inclusive.
            :type i: int 
            :type j: int
            :rtype: int 
            """
            return self.accu[j + 1] - self.accu[i]
    
    
    # Your NumArray object will be instantiated and called as such:
    # numArray = NumArray(nums)
    # numArray.sumRange(0, 1)
    # numArray.sumRange(1, 2)

</details>
