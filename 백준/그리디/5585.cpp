#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int input;
    cin >> input;

    input = 1000 - input;
    int coins[6] = {500,
                    100,
                    50,
                    10,
                    5,
                    1};

    int cnt = 0;
    for (int i = 0; i < 6; i++)
    {
        if (coins[i] > input)
            continue;
        cnt += input / coins[i];
        input = input % coins[i];
    }
    cout << cnt << "\n";

    return 0;
}