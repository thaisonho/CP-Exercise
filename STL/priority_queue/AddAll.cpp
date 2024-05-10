#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int N;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(cin >> N && N != 0) {
        int tmp;
        for(int i = 0; i < N; ++i) {
            cin >> tmp;
            pq.push(tmp);
        }

        int ans = 0;

        // get the 2 min number in pq, then add, erase, and append new number
        while(true) {
            int a = pq.top();
            pq.pop();
            int b= pq.top();
            pq.pop();

            ans += a + b;
            if(pq.empty()) break;
            pq.push(a + b);
        }

        cout << ans << '\n';
    }
}