// Link: https://vn.spoj.com/problems/AMSSEQ/

#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001], f[10001], res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 1; i <= n; ++i)
    {
        f[i] = -9999;
        for (int j = 1; j <= k; ++j)
        {
            f[i] = max(f[i], f[i - j] + arr[i]);
            res = max(res, f[i]);
        }
    }
    cout << res;
}