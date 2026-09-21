class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    void backtrack(vector<int>& candidates, int start, int target){
        if(target == 0){
            ans.push_back(current);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i - 1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
            current.push_back(candidates[i]);
            backtrack(candidates, i + 1, target - candidates[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return ans;
    }
};