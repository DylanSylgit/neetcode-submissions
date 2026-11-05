#include <cmath>
#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret;

        // distances sorted
        using Element = std::pair<int,std::vector<int>>;
        std::priority_queue<Element,std::vector<Element>,std::greater<Element> > heap;

        for (std::vector<int> point : points) {
            int distance = (point[0] - 0)*(point[0] - 0) + (point[1]-0)*(point[1]-0);
            
            heap.push({distance,point});
        }
        ret.reserve(k);
        for (int i = 0; i < k; i++) {
            ret.push_back(heap.top().second);
            heap.pop();
        }

        return ret;


    }
};
