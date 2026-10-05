# Open the Lock

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | October 5, 2026 |
| **Tags** | Array, Hash Table, String, Breadth-First Search, Bidirectional Search |
| **Link** | [View Problem](https://leetcode.com/problems/open-the-lock/) |
| **Runtime** | 167 ms |
| **Memory** | 39 MB |

## Problem Description

<p>You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: <code>'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'</code>. The wheels can rotate freely and wrap around: for example we can turn <code>'9'</code> to be <code>'0'</code>, or <code>'0'</code> to be <code>'9'</code>. Each move consists of turning one wheel one slot.</p>

<p>The lock initially starts at <code>'0000'</code>, a string representing the state of the 4 wheels.</p>

<p>You are given a list of <code>deadends</code> dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.</p>

<p>Given a <code>target</code> representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> deadends = ["0201","0101","0102","1212","2002"], target = "0202"
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
A sequence of valid moves would be "0000" -&gt; "1000" -&gt; "1100" -&gt; "1200" -&gt; "1201" -&gt; "1202" -&gt; "0202".
Note that a sequence like "0000" -&gt; "0001" -&gt; "0002" -&gt; "0102" -&gt; "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> deadends = ["8888"], target = "0009"
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can turn the last wheel in reverse to move from "0000" -&gt; "0009".
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
<strong>Output:</strong> -1
<strong>Explanation:</strong> We cannot reach the target without getting stuck.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= deadends.length &lt;= 500</code></li>
	<li><code>deadends[i].length == 4</code></li>
	<li><code>target.length == 4</code></li>
	<li>target <strong>will not be</strong> in the list <code>deadends</code>.</li>
	<li><code>target</code> and <code>deadends[i]</code> consist of digits only.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 💯Faster✅💯Lesser✅Detailed Explaination🎯BFS🧠Step-by-Step Explaination✅Python🐍Java🍵C+
**Author**: [@Mohammed_Raziullah_Ansari](https://leetcode.com/Mohammed_Raziullah_Ansari/)
**Upvotes**: 116 👍
**Link**: [View Original Post](https://leetcode.com/problems/open-the-lock/solutions/5057116/)

---

# \uD83D\uDE80 Hi, I\'m [Mohammed Raziullah Ansari](https://leetcode.com/Mohammed_Raziullah_Ansari/), and I\'m excited to share solution to this question with detailed explanation:

# \uD83C\uDFAFProblem Explaination: 
You have a lock that can be opened by turning the dial left or right. The lock initially starts at the combination "0000". You are given a list of dead-end combinations, which are combinations that cannot be used to open the lock. Your goal is to reach a target combination using the minimum number of turns, where each turn involves changing one digit of the lock by one increment (either +1 or -1). 

### \uD83D\uDDD2\uFE0FProblem Details
- **Input**: 
  - `deadends`: A list of strings representing dead-end combinations.
  - `target`: The target combination that you need to reach.
  
- **Output**: 
  - The minimum number of turns required to reach the target combination from "0000", or -1 if it\'s impossible.
### \uD83D\uDEABConstraints
- Each digit on the lock can move from \'0\' to \'9\'.
- You cannot use the combinations listed in `deadends` to open the lock.
- The lock wraps around, meaning \'0\' can be incremented to \'9\' and vice versa.

# \u2705Approach:
The problem can be solved using a Breadth-First Search (BFS) approach. Below is the step-by-Step breakdown of the approach:

1. **Initialization**:
   - Start with the initial combination "0000".
   - Use a set to keep track of dead-end combinations (`deadends`) for quick lookup.
   - Use a queue (or deque) to perform BFS. Start by adding the initial combination to the queue.

2. **BFS Loop**:
   - Begin a loop while the queue is not empty:
     - Dequeue a combination from the front of the queue.
     - If this combination matches the `target`, return the number of moves taken.
     - If it\'s a dead-end (in `deadends`), skip it.
     - Otherwise, generate all possible next combinations by incrementing or decrementing each digit of the current combination (there are 8 possible next combinations for each state).
     - Add valid, unvisited combinations to the queue (i.e., combinations that are not in `deadends` and have not been visited yet). Mark these combinations as visited to avoid redundant processing.

3. **Edge Cases**:
   - If the `target` is in `deadends`, return -1 immediately since the target cannot be reached.
   - If the `target` is "0000", return 0 as no moves are needed.

# Let\'s walkthrough\uD83D\uDEB6\uD83C\uDFFB\u200D\u2642\uFE0F the implementation process with an example for better understanding\uD83C\uDFAF:

Let\'s use the input `deadends = ["8888"], target = "0009"` and go through each Step of the simulation.

#### Step 0:
```
Queue: [(\'0000\', 0)]
Visited: [\'0\']
Current Combination: 0000 
```

#### Step 1:
```
Queue: [(\'9000\', 1), (\'1000\', 1), (\'0900\', 1), (\'0100\', 1), (\'0090\', 1), (\'0010\', 1), (\'0009\', 1), (\'0001\', 1)]
Visited: [\'0001\', \'1000\', \'0100\', \'0900\', \'0090\', \'0\', \'0009\', \'0010\', \'9000\']
Current Combination: 9000 
```

#### Step 2:
```
Queue: [(\'1000\', 1), (\'0900\', 1), (\'0100\', 1), (\'0090\', 1), (\'0010\', 1), (\'0009\', 1), (\'0001\', 1), (\'8000\', 2), (\'0000\', 2), (\'9900\', 2), (\'9100\', 2), (\'9090\', 2), (\'9010\', 2), (\'9009\', 2), (\'9001\', 2)]
Visited: [\'0000\', \'9100\', \'0001\', \'9010\', \'1000\', \'9090\', \'9009\', \'0100\', \'0900\', \'9900\', \'0090\', \'0\', \'0009\', \'0010\', \'9001\', \'9000\', \'8000\']
Current Combination: 1000
``` 

#### Step 3:
```
Queue: [(\'0900\', 1), (\'0100\', 1), (\'0090\', 1), (\'0010\', 1), (\'0009\', 1), (\'0001\', 1), (\'8000\', 2), (\'0000\', 2), (\'9900\', 2), (\'9100\', 2), (\'9090\', 2), (\'9010\', 2), (\'9009\', 2), (\'9001\', 2), (\'2000\', 2), (\'1900\', 2), (\'1100\', 2), (\'1090\', 2), (\'1010\', 2), (\'1009\', 2), (\'1001\', 2)]
Visited: [\'1090\', \'0009\', \'9001\', \'9010\', \'9090\', \'0900\', \'0\', \'0010\', \'8000\', \'1010\', \'9100\', \'0001\', \'1000\', \'9009\', \'0100\', \'0000\', \'0090\', \'1009\', \'9000\', \'1100\', \'1001\', \'1900\', \'2000\', \'9900\']
Current Combination: 0900 
```

#### Step 4:
```
Queue: [(\'0100\', 1), (\'0090\', 1), (\'0010\', 1), (\'0009\', 1), (\'0001\', 1), (\'8000\', 2), (\'0000\', 2), (\'9900\', 2), (\'9100\', 2), (\'9090\', 2), (\'9010\', 2), (\'9009\', 2), (\'9001\', 2), (\'2000\', 2), (\'1900\', 2), (\'1100\', 2), (\'1090\', 2), (\'1010\', 2), (\'1009\', 2), (\'1001\', 2), (\'0800\', 2), (\'0990\', 2), (\'0910\', 2), (\'0909\', 2), (\'0901\', 2)]
Visited: [\'1090\', \'0910\', \'0009\', \'9001\', \'9010\', \'9090\', \'0900\', \'0\', \'0010\', \'8000\', \'1010\', \'9100\', \'0001\', \'1000\', \'9009\', \'0100\', \'0990\', \'0000\', \'0090\', \'1009\', \'0909\', \'9000\', \'0901\', \'1100\', \'1001\', \'1900\', \'2000\', \'9900\', \'0800\']
Current Combination: 0100 
```

#### Step 5:
```
Queue: [(\'0090\', 1), (\'0010\', 1), (\'0009\', 1), (\'0001\', 1), (\'8000\', 2), (\'0000\', 2), (\'9900\', 2), (\'9100\', 2), (\'9090\', 2), (\'9010\', 2), (\'9009\', 2), (\'9001\', 2), (\'2000\', 2), (\'1900\', 2), (\'1100\', 2), (\'1090\', 2), (\'1010\', 2), (\'1009\', 2), (\'1001\', 2), (\'0800\', 2), (\'0990\', 2), (\'0910\', 2), (\'0909\', 2), (\'0901\', 2), (\'0200\', 2), (\'0190\', 2), (\'0110\', 2), (\'0109\', 2), (\'0101\', 2)]
Visited: [\'1090\', \'0910\', \'0101\', \'0009\', \'9001\', \'9010\', \'9090\', \'0900\', \'0\', \'0010\', \'8000\', \'1010\', \'9100\', \'0001\', \'1000\', \'0109\', \'9009\', \'0100\', \'0990\', \'0000\', \'0090\', \'1009\', \'0909\', \'9000\', \'0901\', \'1100\', \'1001\', \'1900\', \'2000\', \'0200\', \'9900\', \'0190\', \'0800\', \'0110\']
Current Combination: 0090 
```

#### Step 6:
```
Queue: [(\'0010\', 1), (\'0009\', 1), (\'0001\', 1), (\'8000\', 2), (\'0000\', 2), (\'9900\', 2), (\'9100\', 2), (\'9090\', 2), (\'9010\', 2), (\'9009\', 2), (\'9001\', 2), (\'2000\', 2), (\'1900\', 2), (\'1100\', 2), (\'1090\', 2), (\'1010\', 2), (\'1009\', 2), (\'1001\', 2), (\'0800\', 2), (\'0990\', 2), (\'0910\', 2), (\'0909\', 2), (\'0901\', 2), (\'0200\', 2), (\'0190\', 2), (\'0110\', 2), (\'0109\', 2), (\'0101\', 2), (\'0080\', 2), (\'0099\', 2), (\'0091\', 2)]
Visited: [\'1090\', \'0099\', \'0910\', \'0101\', \'0009\', \'9001\', \'9010\', \'0080\', \'9090\', \'0900\', \'0\', \'0010\', \'0091\', \'8000\', \'1010\', \'9100\', \'0001\', \'1000\', \'0109\', \'9009\', \'0100\', \'0990\', \'0000\', \'0090\', \'1009\', \'0909\', \'9000\', \'0901\', \'1100\', \'1001\', \'1900\', \'2000\', \'0200\', \'9900\', \'0190\', \'0800\', \'0110\']
Current Combination: 0010 
```

#### Step 7:
```
Queue: [(\'0009\', 1), (\'0001\', 1), (\'8000\', 2), (\'0000\', 2), (\'9900\', 2), (\'9100\', 2), (\'9090\', 2), (\'9010\', 2), (\'9009\', 2), (\'9001\', 2), (\'2000\', 2), (\'1900\', 2), (\'1100\', 2), (\'1090\', 2), (\'1010\', 2), (\'1009\', 2), (\'1001\', 2), (\'0800\', 2), (\'0990\', 2), (\'0910\', 2), (\'0909\', 2), (\'0901\', 2), (\'0200\', 2), (\'0190\', 2), (\'0110\', 2), (\'0109\', 2), (\'0101\', 2), (\'0080\', 2), (\'0099\', 2), (\'0091\', 2), (\'0020\', 2), (\'0019\', 2), (\'0011\', 2)]
Visited: [\'1090\', \'0019\', \'0099\', \'0910\', \'0101\', \'0009\', \'9001\', \'9010\', \'0020\', \'0080\', \'9090\', \'0900\', \'0\', \'0010\', \'0091\', \'8000\', \'1010\', \'9100\', \'0001\', \'1000\', \'0109\', \'9009\', \'0100\', \'0990\', \'0000\', \'0090\', \'1009\', \'0909\', \'9000\', \'0901\', \'1100\', \'1001\', \'1900\', \'2000\', \'0200\', \'9900\', \'0190\', \'0011\', \'0800\', \'0110\']
Current Combination: 0009 
```
#### Final result:
```
Minimum moves required: 1
```

# Code\uD83D\uDC69\uD83C\uDFFB\u200D\uD83D\uDCBB:
```Python []
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        # Convert deadends to a set for O(1) lookup
        deadends = set(deadends)
        if "0000" in deadends:
            return -1
        
        # Initialize BFS
        queue = deque([(\'0000\', 0)])  # (current_combination, moves)
        visited = set(\'0000\')
        
        # BFS loop
        while queue:
            current_combination, moves = queue.popleft()
            
            # Check if we\'ve reached the target
            if current_combination == target:
                return moves
            
            # Generate next possible combinations
            for i in range(4):
                for delta in [-1, 1]:
                    new_digit = (int(current_combination[i]) + delta) % 10
                    new_combination = (
                        current_combination[:i] + str(new_digit) + current_combination[i+1:]
                    )
                    
                    # Check if the new combination is valid and not visited
                    if new_combination not in visited and new_combination not in deadends:
                        visited.add(new_combination)
                        queue.append((new_combination, moves + 1))
        
        # If target is not reachable
        return -1
```
```Java []
import java.util.*;

class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> deadendSet = new HashSet<>(Arrays.asList(deadends));
        if (deadendSet.contains("0000")) {
            return -1;
        }
        
        Queue<Pair<String, Integer>> queue = new LinkedList<>();
        queue.offer(new Pair<>("0000", 0));
        Set<String> visited = new HashSet<>();
        visited.add("0000");
        
        while (!queue.isEmpty()) {
            Pair<String, Integer> current = queue.poll();
            String currentCombination = current.getKey();
            int moves = current.getValue();
            
            if (currentCombination.equals(target)) {
                return moves;
            }
            
            for (int i = 0; i < 4; i++) {
                for (int delta : new int[]{-1, 1}) {
                    int newDigit = (currentCombination.charAt(i) - \'0\' + delta + 10) % 10;
                    String newCombination = currentCombination.substring(0, i) +
                                             newDigit +
                                             currentCombination.substring(i + 1);
                    
                    if (!visited.contains(newCombination) && !deadendSet.contains(newCombination)) {
                        visited.add(newCombination);
                        queue.offer(new Pair<>(newCombination, moves + 1));
                    }
                }
            }
        }
        
        return -1; // Target is not reachable
    }
}
```
```C++ []
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        if (deadendSet.count("0000")) {
            return -1;
        }
        
        queue<pair<string, int>> queue;
        queue.push({"0000", 0});
        unordered_set<string> visited;
        visited.insert("0000");
        
        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop();
            string currentCombination = current.first;
            int moves = current.second;
            
            if (currentCombination == target) {
                return moves;
            }
            
            for (int i = 0; i < 4; i++) {
                for (int delta : {-1, 1}) {
                    int newDigit = (currentCombination[i] - \'0\' + delta + 10) % 10;
                    string newCombination = currentCombination;
                    newCombination[i] = \'0\' + newDigit;
                    
                    if (visited.find(newCombination) == visited.end() && deadendSet.find(newCombination) == deadendSet.end()) {
                        visited.insert(newCombination);
                        queue.push({newCombination, moves + 1});
                    }
                }
            }
        }
        
        return -1; // Target is not reachable
    }
};
```

</details>
