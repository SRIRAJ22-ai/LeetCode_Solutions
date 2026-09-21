class Solution {
public:
    bool canPlace(vector<int>& position, int m, int distance){
        int balls = 1;
        int lastPosition = position[0];
        for(int i = 1; i < position.size(); i++){
            if(position[i] - lastPosition >= distance){
                balls++;
                lastPosition = position[i];
            }
            if(balls >= m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back() - position.front();
        int answer = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canPlace(position, m, mid)){
                answer = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return answer;
    }
};