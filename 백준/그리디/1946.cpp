#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int document, interview;
};
int compare(Node t, Node v)
{
    if (t.document < v.document)
        return 1;
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        int n, result = 1;
        vector<Node> q;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int d, inter;
            cin >> d >> inter;
            Node nn = {d, inter};
            q.push_back(nn);
        }
        sort(q.begin(), q.end(), compare);

        Node lowest = q[0];
        for (int i = 1; i < n; i++)
        {
            if (q[i].interview <= lowest.interview)
            {
                result++;
                lowest = q[i];
            }
        }
        cout << result << "\n";
    }
    return 0;
}