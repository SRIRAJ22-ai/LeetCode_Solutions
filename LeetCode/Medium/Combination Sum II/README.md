# Combination Sum II

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 21, 2026 |
| **Tags** | Array, Backtracking |
| **Link** | [View Problem](https://leetcode.com/problems/combination-sum-ii/) |
| **Runtime** | 0 ms |
| **Memory** | 14.3 MB |

## Problem Description

<p>Given a collection of candidate numbers (<code>candidates</code>) and a target number (<code>target</code>), find all unique combinations in <code>candidates</code>&nbsp;where the candidate numbers sum to <code>target</code>.</p>

<p>Each number in <code>candidates</code>&nbsp;may only be used <strong>once</strong> in the combination.</p>

<p><strong>Note:</strong>&nbsp;The solution set must not contain duplicate combinations.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> candidates = [10,1,2,7,6,1,5], target = 8
<strong>Output:</strong> 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> candidates = [2,5,2,1,2], target = 5
<strong>Output:</strong> 
[
[1,2,2],
[5]
]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;candidates.length &lt;= 100</code></li>
	<li><code>1 &lt;=&nbsp;candidates[i] &lt;= 50</code></li>
	<li><code>1 &lt;= target &lt;= 30</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Combination Sum I, II and III + Subsets I and II + Permutations I and II: One stop  C++ solutions
**Author**: [@Praful_kr](https://leetcode.com/Praful_kr/)
**Upvotes**: 276 👍
**Link**: [View Original Post](https://leetcode.com/problems/combination-sum-ii/solutions/1277764/)

---

**SUBSETS** 
https://leetcode.com/problems/subsets
```
class Solution {
public:
    vector<vector<int>> result;
    
    void powerset(vector<int> nums, int curr, vector<int> res, int n){
        if(curr == n){
            result.push_back(res);
            return;
        }
        powerset(nums, curr+1, res, n);
        res.push_back(nums[curr]);
        powerset(nums, curr+1, res, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        powerset(nums, 0, res, n);
        return result;
    }
};
```

**SUBSETS II**
https://leetcode.com/problems/subsets-ii/
```
class Solution {
public:
    vector<vector<int>> result;
    
    void subs(vector<int> &nums, int curr, vector<int> &res){
        result.push_back(res);
        for(int i = curr; i < nums.size(); i++){
            if(i!=curr && nums[i]==nums[i-1]){
                continue;
            }
            res.push_back(nums[i]);
            subs(nums, i+1, res);
            res.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0){
            return result;
        }
        vector<int> res;
        sort(nums.begin(), nums.end());
        subs(nums, 0, res);
        return result;
    }
};
```
----------------------------------------------------------------------------------
**PERMUTATIONS**
https://leetcode.com/problems/permutations/
```
class Solution {
public:
    
    vector<vector<int>> result;
    
    vector<int> swap(vector<int> &nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        return nums;
    }
    
    void perm(vector<int> &nums, int l, int r){
        if(l==r){
            result.push_back(nums);
            return;
        }
        for(int i = l; i <= r; i++){
            nums = swap(nums, l, i);
            perm(nums, l+1, r);
            nums = swap(nums, l, i);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums, 0, nums.size()-1);
        return result;
    } 
};
```
**PERMUTATIONS II**
https://leetcode.com/problems/permutations-ii/
```
class Solution {
public:
    vector<vector<int>> result;
    
    vector<int> swap(vector<int> &nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        return nums;
    }
    
    void perm(vector<int> &nums, int l, int r){
        if(l==r){
            result.push_back(nums);
            return;
        }
        set<int> s;
        for(int i = l; i <= r; i++){
                if(s.find(nums[i]) != s.end() )
                    continue;
                s.insert(nums[i]);
                nums = swap(nums, l, i);
                perm(nums, l+1, r);
                nums = swap(nums, l, i);  
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        perm(nums, 0, nums.size()-1);
        return result;  
    }
};
```
-------------------------------------------------------------------------------------------
**COMBINATION SUM**
https://leetcode.com/problems/combination-sum/
```
class Solution {
public:
    vector<vector<int>> result;
    
    void comSum(vector<int> &curr, int curInd, int sum, vector<int> &candidates, int target, int n){
        if(sum == target){
            result.push_back(curr);
            return;
        }      
        else if(sum > target){
            return;
        }
        
        for(int i = curInd; i < n; i++){
            curr.push_back(candidates[i]);
            sum += candidates[i];
            comSum(curr, i, sum, candidates, target, n);
            sum -= candidates[i];
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        int sum = 0;
        int n = candidates.size();
        comSum(curr, 0, sum, candidates, target, n);
        return result;
    }
};
```
**COMBINATION SUM II**
https://leetcode.com/problems/combination-sum-ii/
```
class Solution {
public:
    vector<vector<int>> result;
    
    void comsum(vector<int> &curr, int target, int sum, vector<int> &candidates, int curInd, int n){
        if(target == sum){
            result.push_back(curr);
            return;
        }
        else if(sum>target){
            return;
        }
        
        for(int i = curInd; i < n; i++){
            if(i != curInd && candidates[i]==candidates[i-1])               //to avoid picking up the same combnations i.e. we don\'t pick same element for certain kth position of a combination 
                continue;
            sum += candidates[i];
            curr.push_back(candidates[i]);
            comsum(curr, target, sum, candidates, i+1, n);
            sum -= candidates[i];
            curr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        comsum(curr, target, 0, candidates, 0, n);
        return result;
    }
};
```
**COMBINATION SUM III**
https://leetcode.com/problems/combination-sum-iii/
```
class Solution {
public:
    vector<vector<int>> result;
    void comsum(vector<int> &curr, int k, int n, int sum, int size, int index){
        if(size==k && sum == n){
            result.push_back(curr);
            return;
        }
        else if(size>k || sum>n)
            return;
        
        for(int i = index; i <= 9; i++){
            sum += i;
            curr.push_back(i);
            comsum(curr, k, n, sum, size+1, i+1);
            sum -= i;
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        comsum(curr, k, n, 0, 0, 1);
        return result;
    }
};
```

</details>
