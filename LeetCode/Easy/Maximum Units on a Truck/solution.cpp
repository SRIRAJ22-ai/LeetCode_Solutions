class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });
        int units = 0;

        for (auto box : boxTypes) {
            int boxes = box[0];
            int unitsPerBox = box[1];
            int take = min(boxes, truckSize);

            units += take * unitsPerBox;
            truckSize -= take;
            if (truckSize == 0) {
                break;
            }
        }
        return units;
    }
};