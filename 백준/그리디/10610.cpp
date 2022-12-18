#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
priority_queue<int> q;
int main()
{
    freopen("input.txt", "r", stdin);
    string input;
    cin >> input;
    long result;
    int check_zero = 0, sum = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] - '0' == 0)
            check_zero = 1;
        sum += input[i] - '0';
        q.push(input[i] - '0');
    }
    if (check_zero == 0 || sum % 3 != 0)
    {
        cout << "-1\n";
        return 0;
    }
    else
    {
        string result;
        while (!q.empty())
        {
            int t = q.top();
            q.pop();
            result.append(to_string(t));
        }
        cout << result << "\n";
    }
    return 0;
}