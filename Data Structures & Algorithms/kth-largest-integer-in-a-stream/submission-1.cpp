#include <algorithm>
#include <utility>
#include <vector>

class KthLargest {
private:
    vector<int> v;
    int kV;
public:
    KthLargest(int k, vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        v = std::move(nums);
        kV = k;
    }
    
    int add(int val) {
        int l = 0;
        int r = v.size()-1;
        while (l <= r) {
            int m = (l + r) /2;
            if (v[m] < val) {
                l = m+1;
            }
            else {
                r = m -1;
            }
        }
        v.insert(v.begin() + l,val);
        return v[v.size() - kV];
    }
};
