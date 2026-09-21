class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sum = 0;
                int count = 0;
                for(int di = -1; di <= 1; di++){
                    for(int dj = -1; dj <= 1; dj++){
                        int ni = i + di;
                        int nj = j + dj;
                        if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                            sum += img[ni][nj];
                            count++;
                        }
                    }
                }
                ans[i][j] = sum / count;
            }
        }
        return ans;
    }
};