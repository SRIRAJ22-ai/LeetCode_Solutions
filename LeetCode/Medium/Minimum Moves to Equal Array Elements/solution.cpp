class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minimum = *min_element(nums.begin(), nums.end());
        int moves = 0;
        for(int num : nums){
            moves += num - minimum;
        }
        return moves;
    }
};