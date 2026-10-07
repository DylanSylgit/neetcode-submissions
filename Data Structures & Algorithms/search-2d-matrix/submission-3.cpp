class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() * matrix[0].size() - 1;
        int n = matrix[0].size();

        while (l <= r) {
            int m = l + (r-l) / 2;
            int mid = matrix[m/n][m%n];

            if (mid < target) {
                l = m + 1;
            }
            else if (mid > target) {
                r = m - 1;
            }
            else {
                return true;
            }
        }
        return false;


    }
};
