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
    scanf("%d", &n);
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int w;
        scanf("%d", &w);
        q.push(w);
    }
    int result = -1, ww = 1;
    while (!q.empty())
    {
        int t = q.top();
        q.pop();
        if (result == -1 || result < t * ww)
        {
            result = t * ww;
        }
        ww++;
    }
    cout << result << "\n";

    return 0;
}