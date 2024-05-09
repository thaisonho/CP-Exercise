// Link: https://leetcode.com/problems/max-value-of-equation/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> dq;
        int ans = -1e9 + 7;

        for (const vector<int>& point : points) {
            const int x = point[0],
                y = point[1];

            while (!dq.empty() && x - dq.front().second > k) {
                dq.pop_front();
            }

            if (!dq.empty()) {
                ans = max(ans, y + x + dq.front().first);
            }

            while (!dq.empty() && y - x >= dq.back().first) {
                dq.pop_back();
            }

            dq.push_back(make_pair(y - x, x));
        }

        return ans;
    }
};