#include <iostream>
using namespace std;
#include <cmath>

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;
        int m = (l + r) / 2;

        while (l <= r) {
            m = (r + l) / 2;
            int mid = nums[m];
            int right = nums[r];
            int left = nums[l];

            if (mid == target){
                return m;
            }
            
            if (left <= mid){
                // target is between l and m
                if (left <= target and target < mid){
                    r = m -1;
                }
                else {
                    l = m + 1;
                }
            }
            else {
                if (target <= right and target > mid){
                    l = m +1;
                }
                else {
                    r = m-1;
                }
            }
        }
        return -1;
    }
};
