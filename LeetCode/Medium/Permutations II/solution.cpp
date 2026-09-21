class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    void backtrack(vector<int>& nums, vector<bool>& used) {
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            current.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used);
            used[i] = false;
            current.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return ans;
    }
};