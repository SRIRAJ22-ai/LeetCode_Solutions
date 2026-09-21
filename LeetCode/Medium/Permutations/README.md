# Permutations

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 21, 2026 |
| **Tags** | Array, Backtracking |
| **Link** | [View Problem](https://leetcode.com/problems/permutations/) |
| **Runtime** | 0 ms |
| **Memory** | 11.2 MB |

## Problem Description

<p>Given an array <code>nums</code> of distinct integers, return all the possible <span data-keyword="permutation-array" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_t_" data-state="closed" class="">permutations</button></span>. You can return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0,1]
<strong>Output:</strong> [[0,1],[1,0]]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> [[1]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 6</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li>All the integers of <code>nums</code> are <strong>unique</strong>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Backtracking Solution || C++ || Easy To Understand || With explanation
**Author**: [@vivek_javiya](https://leetcode.com/vivek_javiya/)
**Upvotes**: 153 👍
**Link**: [View Original Post](https://leetcode.com/problems/permutations/solutions/1257633/)

---


Suppose if give string is ABC then recursive tree like this
![image](https://assets.leetcode.com/users/images/0865f0cf-1f8a-4164-9543-4bf13aebcb59_1623088635.478572.jpeg)


```
class Solution {
public:
    vector<vector<int>> result;
    
    // Backtracking
    void permutation(vector<int> &nums,int i,int n){
        if(i==n){
            result.push_back(nums);
            return ;
        }

        for(int j=i;j<=n;j++){
            swap( nums[i],nums[j]);
            permutation(nums,i+1,n);
            swap( nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        permutation(nums,0,nums.size()-1);
        
        return result;
    }
};
```

</details>
