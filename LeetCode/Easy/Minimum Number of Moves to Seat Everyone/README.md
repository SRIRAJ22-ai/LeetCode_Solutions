# Minimum Number of Moves to Seat Everyone

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | September 26, 2026 |
| **Tags** | Array, Greedy, Sorting, Counting Sort |
| **Link** | [View Problem](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/) |
| **Runtime** | 0 ms |
| **Memory** | 21.7 MB |

## Problem Description

<p>There are <code>n</code> <strong>availabe </strong>seats and <code>n</code> students <strong>standing</strong> in a room. You are given an array <code>seats</code> of length <code>n</code>, where <code>seats[i]</code> is the position of the <code>i<sup>th</sup></code> seat. You are also given the array <code>students</code> of length <code>n</code>, where <code>students[j]</code> is the position of the <code>j<sup>th</sup></code> student.</p>

<p>You may perform the following move any number of times:</p>

<ul>
	<li>Increase or decrease the position of the <code>i<sup>th</sup></code> student by <code>1</code> (i.e., moving the <code>i<sup>th</sup></code> student from position&nbsp;<code>x</code>&nbsp;to <code>x + 1</code> or <code>x - 1</code>)</li>
</ul>

<p>Return <em>the <strong>minimum number of moves</strong> required to move each student to a seat</em><em> such that no two students are in the same seat.</em></p>

<p>Note that there may be <strong>multiple</strong> seats or students in the <strong>same </strong>position at the beginning.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> seats = [3,1,5], students = [2,7,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The students are moved as follows:
- The first student is moved from position 2 to position 1 using 1 move.
- The second student is moved from position 7 to position 5 using 2 moves.
- The third student is moved from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> seats = [4,1,5,9], students = [1,3,2,6]
<strong>Output:</strong> 7
<strong>Explanation:</strong> The students are moved as follows:
- The first student is not moved.
- The second student is moved from position 3 to position 4 using 1 move.
- The third student is moved from position 2 to position 5 using 3 moves.
- The fourth student is moved from position 6 to position 9 using 3 moves.
In total, 0 + 1 + 3 + 3 = 7 moves were used.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> seats = [2,2,6,6], students = [1,3,2,6]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Note that there are two seats at position 2 and two seats at position 6.
The students are moved as follows:
- The first student is moved from position 1 to position 2 using 1 move.
- The second student is moved from position 3 to position 6 using 3 moves.
- The third student is not moved.
- The fourth student is not moved.
In total, 1 + 3 + 0 + 0 = 4 moves were used.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == seats.length == students.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= seats[i], students[j] &lt;= 100</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅Beats 100% - Explained with [ Video ] - C++/Java/Python/JS - Arrays - Sorting - Interview Solution
**Author**: [@lancertech6](https://leetcode.com/lancertech6/)
**Upvotes**: 124 👍
**Link**: [View Original Post](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/solutions/5304430/)

---

![Screenshot 2024-06-13 065049.png](https://assets.leetcode.com/users/images/f1166a57-0d26-4fef-a119-f59ee16b413a_1718242226.1727304.png)


# YouTube Video Explanation:

<!-- **If you want a video for this question please write in the comments** -->

<!-- https://www.youtube.com/watch?v=ujU-jeO1v-k -->

https://youtu.be/2gkefxP-cQw

**\uD83D\uDD25 Please like, share, and subscribe to support our channel\'s mission of making complex concepts easy to understand.**

Subscribe Link: https://www.youtube.com/@leetlogics/?sub_confirmation=1

*Subscribe Goal: 1900 Subscribers*
*Current Subscribers: 1855*

---
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem requires us to find the minimum number of moves to position each student in a seat such that no two students occupy the same seat. Since the cost of moving a student is the absolute difference between their current position and the target seat position, the optimal way to achieve this is to pair the closest seats with the closest students.

# Approach
<!-- Describe your approach to solving the problem. -->
1. **Sorting**:
   - Sort both the `seats` and `students` arrays. By sorting, we ensure that the smallest available seat is paired with the smallest positioned student, the second smallest seat with the second smallest positioned student, and so on. This minimizes the overall distance each student has to move.
   
2. **Calculate Moves**:
   - Iterate through the sorted arrays and compute the sum of absolute differences between the corresponding elements in the `seats` and `students` arrays. This gives the total number of moves required to seat all students.

# Complexity
- **Time Complexity**: `O(n log n)`
  - Sorting the `seats` and `students` arrays takes \\( O(n \\log n) \\) time each.
  - Calculating the total moves takes \\( O(n) \\) time.
  - Hence, the overall time complexity is dominated by the sorting step, i.e., \\( O(n \\log n) \\).

- **Space Complexity**: `O(1)`
  - No extra space is used other than a few variables to store intermediate results.


# Step by Step Explanation

Let\'s take the example from the problem statement:

**Example**: `seats = [3, 1, 5]`, `students = [2, 7, 4]`

1. **Initial State**:

| Seats | Students |
|-------|----------|
| 3     | 2        |
| 1     | 7        |
| 5     | 4        |

2. **After Sorting**:

| Seats | Students |
|-------|----------|
| 1     | 2        |
| 3     | 4        |
| 5     | 7        |

3. **Calculate Moves**:

| Seat | Student | Moves |
|------|---------|-------|
| 1    | 2       | 1     |
| 3    | 4       | 1     |
| 5    | 7       | 2     |
| **Total Moves** |         | **4**   |

The total number of moves required is 4.




# Code
```java []
class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        int n=seats.length;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += Math.abs(seats[i]-students[i]);
        }
        return sum;
    }
}
```
```C++ []
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
       sort(seats.begin(), seats.end());
       sort(students.begin(), students.end());
        int moves = 0;
        for( int i=0; i<seats.size(); i++)
            moves += abs(seats[i] - students[i]);
        
        return moves;
    }
};
```
```Python []
class Solution:
    def minMovesToSeat(self, seats, students):
        seats.sort()
        students.sort()
        return sum(abs(seat - student) for seat, student in zip(seats, students))
```
```JavaScript []
/**
 * @param {number[]} seats
 * @param {number[]} students
 * @return {number}
 */
var minMovesToSeat = function(seats, students) {
    let moves =0
    seats = seats.sort((a,b)=>b-a)
    students = students.sort((a,b)=>b-a)
    seats.forEach((s,i)=>
    moves = moves+Math.abs(s-students[i]))

    return moves
};
```
![upvote.png](https://assets.leetcode.com/users/images/93ac375b-d4bd-4666-86f3-b1cfdb8dc830_1718242308.1009545.png)

# Another Approach (\u2705Beats 100%)

# Intuition:
To minimize the number of moves required to seat each student, we need to pair each student with an available seat such that the distance between the student\'s position and the seat\'s position is minimized. We can achieve this by sorting the positions of seats and students and then iterating through both arrays simultaneously to calculate the total moves needed.

# Approach:
1. Sort the `seats` and `students` arrays.
2. Initialize a variable `moves` to track the total number of moves.
3. Iterate through both arrays simultaneously.
   - Calculate the absolute difference between the position of the current student and the current seat.
   - Add this difference to `moves`.
4. Return the total number of moves.

# Complexity:
- Time complexity: O(nlogn) due to sorting the arrays.
- Space complexity: O(n) for storing the sorted arrays.

# Code

```java []
class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        int[] pos = new int[101];
        int n = seats.length;
        for(int i = 0; i < n; i++){
            pos[seats[i]]++;
            pos[students[i]]--;
        }
        int res = 0;
        int current = 0;
        for(int i: pos){
            res += Math.abs(current);
            current += i;
        }
        return res;
    }
}
```
```C++ []
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
       vector<int> pos(101, 0);
        int n = seats.size();
        for(int i = 0; i < n; i++){
            pos[seats[i]]++;
            pos[students[i]]--;
        }
        int res = 0;
        int current = 0;
        for(int i: pos){
            res += abs(current);
            current += i;
        }
        return res;
    }
};
```
```Python []
class Solution:
    def minMovesToSeat(self, seats, students):
        pos = [0] * 101
        n = len(seats)
        for i in range(n):
            pos[seats[i]] += 1
            pos[students[i]] -= 1
        res = 0
        current = 0
        for i in pos:
            res += abs(current)
            current += i
        return res
```
```JavaScript []
/**
 * @param {number[]} seats
 * @param {number[]} students
 * @return {number}
 */
var minMovesToSeat = function(seats, students) {
    const pos = new Array(101).fill(0);
        const n = seats.length;
        for(let i = 0; i < n; i++){
            pos[seats[i]]++;
            pos[students[i]]--;
        }
        let res = 0;
        let current = 0;
        for(const i of pos){
            res += Math.abs(current);
            current += i;
        }
        return res;
};
```

</details>
