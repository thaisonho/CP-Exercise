/**
 * @file dijkstra.cpp
 * @author thaisonho (james@thaisonho.onmicrosoft.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m, s, f, u, v;
int d[10000];
int c[10000][10000];
bool Free[10000];

void Init()
{
    for (int i = 1; i <= n; ++i)
        Free[i] = true;
    d[s] = 0;
}

void dijkstra()
{
    while (true)
    {
        int Min = INF;
        u = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (Free[i] && d[i] < Min)
            {
                Min = d[i];
                u = i;
            }
        }
        if (u == 0 || u == f)
            break;
        Free[u] = false;
        for (int v = 1; v <= n; ++i)
        {
            if (Free[i] && d[v] > d[u] + c[u][v])
            {
                d[v] = d[u] + c[u][v];
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s >> f;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == j)
            {
                c[i][j] = 0;
            }
            else
                c[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; ++i)
        cin >> u >> v >> c[u][v];
    Init();
    dijkstra();
    cout << d[f];
}