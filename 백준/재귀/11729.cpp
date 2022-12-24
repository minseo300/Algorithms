#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void hanoi(int n, int source, int aux, int des)
{
    if (n == 1)
    {
        cout << source << " " << des << "\n";
    }
    else
    {
        hanoi(n - 1, source, des, aux);
        cout << source << " " << des << "\n";
        hanoi(n - 1, aux, source, des);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    cout << (int)pow(2, n) - 1 << "\n";
    hanoi(n, 1, 2, 3);

    return 0;
}