class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
        vector<int> answer;
        for(int query : queries){
            int index = upper_bound(prefix.begin(), prefix.end(), query) - prefix.begin();
            answer.push_back(index);
        }
        return answer;
    }
};