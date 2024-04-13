.// Link:

#include <iostream>
#include <queue>

using namespace std;

int t, n, k;
int arr[17001];
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        dq.clear();

        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; ++i) {
            while (!dq.empty() && arr[dq.back()] >= arr[i])
                dq.pop_back();

            dq.push_back(i);

            if (dq.front() + k <= i) dq.pop_front();
            if (i >= k) cout << arr[dq.front()] << ' ';
        }
        cout << '\n';
    }
}
