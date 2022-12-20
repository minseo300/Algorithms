#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node
{
    char w;
    int cnt;
};
bool operator<(Node v, Node t)
{
    if (t.cnt > v.cnt)
        return 1;
    return 0;
}
int dat[300] = {
    0,
};
int nums[300] = {
    0,
};
priority_queue<Node> q;
int main()
{
    freopen("input.txt", "r", stdin);

    int n, number = 9, result = 0;
    cin >> n;
    vector<Node> words;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        int len = word.length();
        for (int j = 0; j < len; j++)
        {
            dat[word[j]] += pow(10, len - j - 1);
        }
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
        Node nn = {(char)i, dat[i]};
        q.push(nn);
    }
    while (!q.empty())
    {
        Node now = q.top();
        q.pop();
        if (nums[now.w] == 0)
        {
            nums[now.w] = number--;
        }
        result += nums[now.w] * now.cnt;
    }
    cout << result << "\n";
    return 0;
}