#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int case_ = 1;
    while (1)
    {
        int l, p, v;
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0)
            break;

        int result = (v / p) * l + min(l, v % p);
        cout << "Case " << case_++ << ": " << result << "\n";
    }

    return 0;
}