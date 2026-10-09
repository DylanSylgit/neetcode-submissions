#include <iostream>
using namespace std;
#include <cmath>

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        int i = 0;
        int j = nums.size() - 1;

        int ret = 1001;

        while (i < j) {
            int m = (j + i) / 2;
            int mid = nums[m];
            int left = nums[i];
            int right = nums[j];
            if (mid < right) {
                j = m;
                ret = min(ret,mid);
            }
            else if (mid > right){
                i = m + 1;
                ret = min(ret,right);
            }

        }

        return ret;
        
    }
};
