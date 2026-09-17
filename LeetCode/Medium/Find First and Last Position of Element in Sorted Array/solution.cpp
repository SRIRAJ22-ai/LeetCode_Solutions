class Solution {
public:
    int low_search(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target) {
                high = mid;
            }
            else low = mid + 1;
        }
        if(low < nums.size() && nums[low] == target) {
            return low;
        }
        return -1;
    }
    int up_search(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] <= target) {
                low = mid + 1;
            }
            else high = mid;
        }
        if(low > 0 && nums[low - 1] == target) return low - 1;
        return - 1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        return {low_search(nums, target), up_search(nums, target)};
    }
};