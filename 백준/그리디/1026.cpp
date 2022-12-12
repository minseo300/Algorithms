#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> a; // 오름차순
priority_queue<int> b;                            // 내림차순
int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int aa;
        cin >> aa;
        a.push(aa);
    }
    for (int i = 0; i < n; i++)
    {
        int bb;
        cin >> bb;
        b.push(bb);
    }
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a.top() * b.top();
        a.pop();
        b.pop();
    }
    cout << s << "\n";

    return 0;
}