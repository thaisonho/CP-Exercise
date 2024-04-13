// Link https://cses.fi/problemset/task/1645/
#include <iostream>
#include <stack>

using namespace std;

const int MAX = 2e5 + 1;
int arr[MAX];
stack<int> candidate;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    candidate.push(0);
    for (int i = 1; i <= n; ++i) {
        while (arr[candidate.top()] >= arr[i])
            candidate.pop();
        cout << candidate.top() << ' ';
        candidate.push(i);
    }
}