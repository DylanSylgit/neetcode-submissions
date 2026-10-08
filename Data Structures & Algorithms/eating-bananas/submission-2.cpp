#include <iostream>
using namespace std;
#include <cmath>
#include <algorithm>
#include <vector>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int k = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                int time = ceil((double)piles[i]/mid);
                hours += time;

                if (hours > h) {
                    low = mid+1;
                    break;
                }
            }
            if (hours <= h) {
                k = min(mid,k);
                high = mid-1;
            }
        }

        return k;
    }
};
