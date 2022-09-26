#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[1000];
int used[1000];
int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        used[arr[i]]++;
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int q = used[i] * (n - used[i]);
        cnt = cnt + q;
        n = n - used[i];
    }
    cout << cnt << "\n";

    return 0;
}