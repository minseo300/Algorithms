#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> dis;
vector<long long> price;
struct Node
{
    long long price, index, distance;
};
bool operator<(Node v, Node t)
{
    if (t.price < v.price)
        return 1;
    return 0;
}
priority_queue<Node> q;
int main()
{
    freopen("input.txt", "r", stdin);
    long long n, total = 0LL, bf = 0LL;
    Node before = {-1LL, 100001LL, 0LL};
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        long long d;
        cin >> d;
        dis.push_back(d);
    }
    for (int i = 0; i < n - 1; i++)
    {
        long long p;
        cin >> p;
        total += p;
        price.push_back(p);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        long long dd;
        dd = dis[i] + bf;
        Node in = {price[i], i, dd};
        q.push(in);
        bf += dis[i];
    }
    long long result = 0LL;
    while (!q.empty())
    {
        Node now = q.top();
        q.pop();
        if (before.index < now.index)
            continue;
        result += (long long)now.price * (long long)(now.distance - before.distance);
        before = now;
    }
    cout << result << "\n";
    return 0;
}