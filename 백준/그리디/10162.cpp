#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int times[3] = {300, 60, 10};
int cnt[3];
int main()
{
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int i = 0; i < 3; i++)
    {
        if (T < times[i])
            continue;

        cnt[i] = T / times[i];
        T = T % times[i];
    }
    if (T != 0)
        cout << "-1";
    else
    {
        for (int i = 0; i < 3; i++)
        {
            cout << cnt[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}