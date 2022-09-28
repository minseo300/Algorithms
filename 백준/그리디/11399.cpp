#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    int arr[1000];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int result = arr[0], before = arr[0];
    for (int i = 1; i < n; i++)
    {
        before += arr[i];
        result += before;
    }
    cout << result << "\n";
    return 0;
}