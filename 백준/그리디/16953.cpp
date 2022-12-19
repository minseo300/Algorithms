#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    long long start, end;
    cin >> start >> end;
    long long result = 1LL;
    while (end != start)
    {
        if (end < start)
        {
            result = -1;
            break;
        }
        if (end % 10 == 1)
            end = end / 10;
        else
        {
            if (end % 2 != 0)
            {
                result = -1;
                break;
            }
            else
                end = end / 2;
        }
        result++;
    }
    cout << result << "\n";

    return 0;
}