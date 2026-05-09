#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int l = 0; l < layers; ++l) {
            int top = l, left = l;
            int bottom = m - 1 - l;
            int right = n - 1 - l;

            vector<int> elements;

            for (int col = left; col <= right; ++col)
                elements.push_back(grid[top][col]);

            for (int row = top + 1; row <= bottom; ++row)
                elements.push_back(grid[row][right]);

            if (bottom > top) {
                for (int col = right - 1; col >= left; --col)
                    elements.push_back(grid[bottom][col]);
            }

            if (left < right) {
                for (int row = bottom - 1; row >= top + 1; --row)
                    elements.push_back(grid[row][left]);
            }

            int len = elements.size();
            int shift = k % len;
            if (shift != 0) {
                rotate(elements.begin(), elements.begin() + shift, elements.end());
            }

            int idx = 0;

            for (int col = left; col <= right; ++col)
                grid[top][col] = elements[idx++];

            for (int row = top + 1; row <= bottom; ++row)
                grid[row][right] = elements[idx++];

            if (bottom > top) {
                for (int col = right - 1; col >= left; --col)
                    grid[bottom][col] = elements[idx++];
            }

            if (left < right) {
                for (int row = bottom - 1; row >= top + 1; --row)
                    grid[row][left] = elements[idx++];
            }
        }

        return grid;
    }
};