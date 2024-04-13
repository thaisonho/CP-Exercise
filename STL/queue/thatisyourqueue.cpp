// Link: https://vjudge.net/problem/UVA-12207
// this code runs in 10ms
// if you want it to be 0ms, don't write any functions, put it all in main()
// I write extra functions just to make the code looks clean :)

#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

void clearQueue(queue<int>& q) {
    while(!q.empty()) q.pop();
}

void initQueue(queue<int>& q, int p, int c) {
    for(int i = 1; i <= min(p, c); ++i) q.push(i);
}

void initQueue(queue<int>& _dest, queue<int>& _src, int emerge) {
    while(!_src.empty()) {
        if(_src.front() != emerge) {
            _dest.push(_src.front());
        }
        _src.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int p, c;
    int test = 0;
    while(true) {
        cin >> p >> c;
        if(p == 0 && c == 0) break;

        clearQueue(q);
        ++test;
        initQueue(q, p, c);
        cout << "Case " << test << ":\n";
        while(c--) {
            char type; cin >> type;
            if(type == 'N') {
                int frontPatient = q.front();
                q.pop();
                q.push(frontPatient);
                cout << frontPatient << '\n';
            }
            else {
                int emerge;
                cin >> emerge;
                queue<int> tmpQueue;
                tmpQueue.push(emerge);
                initQueue(tmpQueue, q, emerge);
                initQueue(q, tmpQueue, -1);
            }
        }
    }
}