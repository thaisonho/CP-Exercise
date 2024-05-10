// Link: https://oj.vnoi.info/problem/kmin

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

struct Element {
    int total, pos_a, pos_b;
    bool operator>(const Element& other) const {
        return total > other.total;
    }
};

int m, n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> m >> n >> k;
    vector<int> arr_a(m), arr_b(n);
    priority_queue<Element, vector<Element>, greater<Element>> pq;

    // read array
    for (int i = 0; i < m; ++i) cin >> arr_a[i];
    for (int i = 0; i < n; ++i) cin >> arr_b[i];

    sort(arr_a.begin(), arr_a.end());

    // push to the pq the smallest number in arr_a sum with every elements in arr_b
    for(int i = 0; i < n; ++i) {
        // emplace data
        pq.push((Element){arr_a[0] + arr_b[i], 0, i});
    }

    // print out the smallest, then another possible smallest elements into the pq
    for(int i = 0; i < k; ++i) {
        Element top = pq.top();
        pq.pop();
        cout << top.total << '\n';
        pq.push((Element) {arr_a[top.pos_a + 1] + arr_b[top.pos_b], top.pos_a + 1, top.pos_b});
    }
}