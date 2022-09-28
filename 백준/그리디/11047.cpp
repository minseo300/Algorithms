#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int n, k;
    int arr[10];

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0, remain = k;
    for (int i = n - 1; i >= 0; i--)
    {
        if (remain < arr[i])
            continue;
        cnt += remain / arr[i];
        remain = remain % arr[i];
    }
    cout << cnt << "\n";
    return 0;
}