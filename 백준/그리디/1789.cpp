#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    long n, i = 1, sum = 0, result = 0;
    cin >> n;
    while (1)
    {
        sum = (i * (i + 1)) / 2;
        if (sum == n)
        {
            result = i;
            break;
        }
        if (sum > n)
        {
            result = i - 1;
            break;
        }
        i++;
    }
    cout << result << "\n";
    return 0;
}