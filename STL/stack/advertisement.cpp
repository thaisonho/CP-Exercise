//Link: https://cses.fi/problemset/task/1142/

#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

stack <int> st;
ll arr[200005];
int leftPosition[200005], rightPosition[200005];
ll ans = -1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    st.push(0);
    for (int i = 1; i <= n; ++i) {
        while (arr[st.top()] >= arr[i]) {
            st.pop();
        }
        leftPosition[i] = st.top();
        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    st.push(n + 1);
    for (int i = n; i >= 1; --i) {
        while (arr[st.top()] >= arr[i]) {
            st.pop();
        }
        rightPosition[i] = st.top();
        st.push(i);
    }

    for (int i = 1; i <= n; ++i) {
        ans = max(ans, arr[i] * (rightPosition[i] - leftPosition[i] - 1));
    }
    cout << ans;
}