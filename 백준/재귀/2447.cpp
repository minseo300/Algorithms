#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
char map[10000][10000];
void run(int y, int x, int n)
{
    if (((y / n) % 3) == 1 && ((x / n) % 3) == 1)
        cout << " ";
    else
    {
        if (n / 3 == 0)
            cout << "*";
        else
            run(y, x, n / 3);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            run(y, x, n);
        }
        cout << "\n";
    }

    return 0;
}