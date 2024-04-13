// Link: https://www.spoj.com/PTIT/problems/BCDAISY/

#include <iostream>
#include <algorithm>

using namespace std;

int d[500];
int m, n, x, y;

int findLeader(int x)
{
    while (x != d[x])
        x = d[x];
    return x;
}

int unionGroup(int x, int y)
{
    x = findLeader(x);
    y = findLeader(y);
    d[max(x, y)] = min(x, y);
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        d[i] = i;
    while (m--)
    {
        cin >> x >> y;
        unionGroup(x, y);
    }
    for (int i = 1; i <= n; ++i)
        if (findLeader(`i) != 1)
            cout << i << '\n';
}