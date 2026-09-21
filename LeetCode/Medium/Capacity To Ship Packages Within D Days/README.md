# Capacity To Ship Packages Within D Days

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 21, 2026 |
| **Tags** | Array, Binary Search |
| **Link** | [View Problem](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) |
| **Runtime** | 10 ms |
| **Memory** | 35 MB |

## Problem Description

<p>A conveyor belt has packages that must be shipped from one port to another within <code>days</code> days.</p>

<p>The <code>i<sup>th</sup></code> package on the conveyor belt has a weight of <code>weights[i]</code>. Each day, we load the ship with packages on the conveyor belt (in the order given by <code>weights</code>). We may not load more weight than the maximum weight capacity of the ship.</p>

<p>Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within <code>days</code> days.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> weights = [1,2,3,4,5,6,7,8,9,10], days = 5
<strong>Output:</strong> 15
<strong>Explanation:</strong> A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> weights = [3,2,2,4,1,4], days = 3
<strong>Output:</strong> 6
<strong>Explanation:</strong> A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> weights = [1,2,3,1,1], days = 4
<strong>Output:</strong> 3
<strong>Explanation:</strong>
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= days &lt;= weights.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= weights[i] &lt;= 500</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Day 53 || Binary Search || Easiest Beginner Friendly Sol
**Author**: [@singhabhinash](https://leetcode.com/singhabhinash/)
**Upvotes**: 175 👍
**Link**: [View Original Post](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/solutions/3216547/)

---

# Intuition of this Problem:\r
The intuition behind this code is that we want to find the minimum capacity of the ship that can ship all the packages within days days. We can use binary search to efficiently search for this minimum capacity.\r
\r
To perform binary search, we need to define the search range [left, right]. The minimum capacity should be at least as large as the largest package, so we set left to be the maximum weight in weights. The maximum capacity should be the sum of weights, so we set right to be the sum of all weights in weights.\r
\r
For each mid value in the search range [left, right], we simulate the shipping process to see if it can be done within days days using a ship with capacity mid. We start with the first package and add packages to the ship until it is full. When the ship is full, we start a new day and continue adding packages until all packages are shipped. We count the number of days needed to ship all packages with the current mid value.\r
\r
If the number of days needed with the current mid value is greater than days, it means that the ship capacity is too small, and we need to increase the capacity. Therefore, we set left = mid + 1. Otherwise, we can try to reduce the capacity by setting right = mid.\r
\r
We repeat this process until left >= right, at which point left is the minimum capacity of the ship that can ship all the packages within days days. We return left as the answer.\r
<!-- Describe your first thoughts on how to solve this problem. -->\r
**NOTE - PLEASE READ APPROACH FIRST THEN SEE THE CODE. YOU WILL DEFINITELY UNDERSTAND THE CODE LINE BY LINE AFTER SEEING THE APPROACH.**\r
\r
# Approach for this Problem:\r
1. Initialize maxWeight as -1 and totalWeight as 0\r
2. Iterate through the weights array and update maxWeight to the maximum weight in the array, and update totalWeight to the sum of all weights in the array\r
3. Use binary search to search for the minimum capacity of the ship that can ship all the packages within days days. Set left endpoint as maxWeight and right endpoint as totalWeight\r
4. While left endpoint is less than right endpoint, calculate mid-point as (left+right)/2\r
5. Simulate the shipping process using mid-point as the ship\'s capacity to see how many days are needed to ship all the packages.\r
6. Keep track of the current weight being loaded onto the ship and the number of days needed to complete the shipment. If the current weight plus the weight of the next package exceeds the mid-point, start a new day and reset the current weight. Repeat this until all the packages have been loaded onto the ship.\r
7. If the number of days needed is greater than days, set left endpoint to mid+1. Otherwise, set right endpoint to mid.\r
8. Continue the binary search until left endpoint is greater than or equal to right endpoint. At this point, left endpoint will be the minimum capacity of the ship that can ship all the packages within days days.\r
<!-- Describe your approach to solving the problem. -->\r
\r
# Humble Request:\r
- If my solution is helpful to you then please **UPVOTE** my solution, your **UPVOTE** motivates me to post such kind of solution.\r
- Please let me know in comments if there is need to do any improvement in my approach, code....anything.\r
- **Let\'s connect on** https://www.linkedin.com/in/abhinash-singh-1b851b188\r
\r
![57jfh9.jpg](https://assets.leetcode.com/users/images/c2826b72-fb1c-464c-9f95-d9e578abcaf3_1674104075.4732099.jpeg)\r
\r
# Code:\r
```C++ []\r
class Solution {\r
public:\r
    int shipWithinDays(vector<int>& weights, int days) {\r
        int maxWeight = -1, totalWeight = 0;\r
        for (int weight : weights) {\r
            maxWeight = max(maxWeight, weight);\r
            totalWeight = totalWeight + weight;\r
        }\r
        //here weight and total weight work as left and right pointer of bunary search\r
        while (maxWeight < totalWeight) {\r
            int midWeight = maxWeight + (totalWeight - maxWeight) / 2;\r
            int daysNeeded = 1, currWeight = 0;\r
            for (int weight : weights) {\r
                if (currWeight + weight > midWeight) {\r
                    daysNeeded++;\r
                    currWeight = 0;\r
                }\r
                currWeight = currWeight + weight;\r
            }\r
            if (daysNeeded > days) {\r
                maxWeight = midWeight + 1;\r
            } else {\r
                totalWeight = midWeight;\r
            }\r
        }\r
        return maxWeight;\r
    }\r
};\r
```\r
```Java []\r
class Solution {\r
    public int shipWithinDays(int[] weights, int days) {\r
        int maxWeight = -1, totalWeight = 0;\r
        for (int weight : weights) {\r
            maxWeight = Math.max(maxWeight, weight);\r
            totalWeight += weight;\r
        }\r
        int left = maxWeight, right = totalWeight;\r
        while (left < right) {\r
            int mid = (left + right) / 2;\r
            int daysNeeded = 1, currWeight = 0;\r
            for (int weight : weights) {\r
                if (currWeight + weight > mid) {\r
                    daysNeeded++;\r
                    currWeight = 0;\r
                }\r
                currWeight += weight;\r
            }\r
            if (daysNeeded > days) {\r
                left = mid + 1;\r
            } else {\r
                right = mid;\r
            }\r
        }\r
        return left;\r
    }\r
}\r
\r
```\r
```Python []\r
class Solution:\r
    def shipWithinDays(self, weights: List[int], days: int) -> int:\r
        maxWeight, totalWeight = -1, 0\r
        for weight in weights:\r
            maxWeight = max(maxWeight, weight)\r
            totalWeight += weight\r
        left, right = maxWeight, totalWeight\r
        while left < right:\r
            mid = (left + right) // 2\r
            daysNeeded, currWeight = 1, 0\r
            for weight in weights:\r
                if currWeight + weight > mid:\r
                    daysNeeded += 1\r
                    currWeight = 0\r
                currWeight += weight\r
            if daysNeeded > days:\r
                left = mid + 1\r
            else:\r
                right = mid\r
        return left\r
\r
```\r
\r
# Time Complexity and Space Complexity:\r
- Time complexity: **O(N*log(S))**, where N is the number of packages (i.e., size of the weights vector) and S is the total weight of all the packages.\r
\r
The reason for this time complexity is the binary search algorithm that is used to find the least weight capacity of the ship. In the worst case, the binary search algorithm performs log(S) iterations, and for each iteration, it needs to traverse the entire weights vector, which takes O(N) time. Therefore, the overall time complexity of the algorithm is O(N*log(S)).\r
<!-- Add your time complexity here, e.g. $$O(n)$$ -->\r
\r
- Space complexity: **O(1)**\r
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

</details>
