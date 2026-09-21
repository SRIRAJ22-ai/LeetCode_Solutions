# Combinations

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 21, 2026 |
| **Tags** | Backtracking |
| **Link** | [View Problem](https://leetcode.com/problems/combinations/) |
| **Runtime** | 71 ms |
| **Memory** | 82.4 MB |

## Problem Description

<p>Given two integers <code>n</code> and <code>k</code>, return <em>all possible combinations of</em> <code>k</code> <em>numbers chosen from the range</em> <code>[1, n]</code>.</p>

<p>You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 4, k = 2
<strong>Output:</strong> [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
<strong>Explanation:</strong> There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1, k = 1
<strong>Output:</strong> [[1]]
<strong>Explanation:</strong> There is 1 choose 1 = 1 total combination.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Clear and simple explanation with intuition: 100% faster
**Author**: [@thisisakshat](https://leetcode.com/thisisakshat/)
**Upvotes**: 186 👍
**Link**: [View Original Post](https://leetcode.com/problems/combinations/solutions/1141903/)

---

**Intuition:** Since we are asked to calculate all the possible combinations , hence we have to use backtracking

**Concept:** In every backtracking problem , there are two things to keep in mind , which we will explore here as well :
*  Base Case: Every problem of backtracking has some base case which tells us at which point we have to stop with the recursion process. In our case, when the size of our array `current` equals to `k` i.e. `current.size()=k`, we stop with the recursion and add it to our final result `ans`.

*   Conditions: There is just one thing to keep in mind here:
   After generating combinations corresponding to a particular number `i` , proceed to the next element by popping the element from the temporary array `current`, as we used that already. 
 
We basically consider a number `i`, generate the combinations corresponding to it by recursively calling it again, and then we pop that element as we are done with it and proceed to the next!!
		
And thats it!! We are done!! Keeping this in mind, here is the code

**Code:**
```
class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int idx, int k,vector<int>&current,int n)
    {
        if(current.size()==k)    // base case
        {
            ans.push_back(current);
            return;
        }
        
        for(int i=idx;i<n+1;i++)
        {
            current.push_back(i);  //consider the current element i
            helper(i+1,k,current,n); // generate combinations
            current.pop_back(); //proceed to next element
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>current;
        helper(1,k,current,n);
        return ans; //return answer
    }
};
```
**For similar problems: [Backtracking Collection](https://leetcode.com/discuss/interview-question/1141947/backtracking-study-and-analysis)**

If you like, please **UPVOTE**

</details>
