# Permutations II

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 21, 2026 |
| **Tags** | Array, Backtracking, Sorting |
| **Link** | [View Problem](https://leetcode.com/problems/permutations-ii/) |
| **Runtime** | 2 ms |
| **Memory** | 12.1 MB |

## Problem Description

<p>Given a collection of numbers, <code>nums</code>,&nbsp;that might contain duplicates, return <em>all possible unique permutations <strong>in any order</strong>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,2]
<strong>Output:</strong>
[[1,1,2],
 [1,2,1],
 [2,1,1]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 8</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: A simple C++ solution in only 20 lines
**Author**: [@guoang](https://leetcode.com/guoang/)
**Upvotes**: 439 👍
**Link**: [View Original Post](https://leetcode.com/problems/permutations-ii/solutions/18596/)

---

    class Solution {
    public:
        void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
            if (i == j-1) {
                res.push_back(num);
                return;
            }
            for (int k = i; k < j; k++) {
                if (i != k && num[i] == num[k]) continue;
                swap(num[i], num[k]);
                recursion(num, i+1, j, res);
            }
        }
        vector<vector<int> > permuteUnique(vector<int> &num) {
            sort(num.begin(), num.end());
            vector<vector<int> >res;
            recursion(num, 0, num.size(), res);
            return res;
        }
    };

</details>
