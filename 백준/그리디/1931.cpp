#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int start, end;
};

bool operator<(Node v, Node t)
{
    // 회의 종료 시간이 빠른 것부터
    if (t.end < v.end)
        return 1;
    if (t.end > v.end)
        return 0;

    return t.start < v.start;
}
priority_queue<Node> q;
int main()
{
    freopen("input.txt", "r", stdin);
    int n, cnt = 0;
    int s, e;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        q.push({s, e});
    }
    Node selected = q.top();
    q.pop();
    cnt++;
    while (!q.empty())
    {
        Node n = q.top();
        q.pop();

        if (n.start < selected.end)
            continue;

        selected = n;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}