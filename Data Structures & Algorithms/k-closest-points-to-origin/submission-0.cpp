#include <cmath>
#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret;

        // distances sorted
        std::priority_queue<float,std::vector<float>,std::greater<float>> heap;

        // m[distance] = {points}
        std::unordered_map<float,vector<vector<int>>> m;

        for (std::vector<int> point : points) {
            float distance = sqrt( (point[0] - 0)*(point[0] - 0) + (point[1]-0)*(point[1]-0) );
            heap.push(distance);
            
            if (m.contains(distance)) {
                m[distance].push_back(point);
            }
            else {
                m[distance] = {point};
            }
        }

        for (int i = 0; i < k; i++) {
            float distance = heap.top();
            heap.pop();
            std::vector<int> point = m[distance].back();
            m[distance].pop_back();
            ret.push_back(point);
        }

        return ret;


    }
};
