#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int n, result = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        q.push(s);
    }
    while (!q.empty())
    {
        int c1 = q.top();
        q.pop();
        if (q.size() == 0)
            break;
        int c2 = q.top();
        q.pop();
        result += c1 + c2;
        q.push(c1 + c2);
    }
    cout << result << "\n";
    return 0;
}