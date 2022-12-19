#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int case_[2] = {0, 0};
int main()
{
    freopen("input.txt", "r", stdin);
    string input;
    cin >> input;
    char before = input[0];
    for (int i = 0; i < input.length(); i++)
    {
        if (before != input[i])
        {
            case_[before - '0']++;
            before = input[i];
        }
    }
    case_[before - '0']++;
    int result;
    if (case_[0] + case_[1] == 1)
        result = 0;
    else
        result = case_[0] <= case_[1] ? case_[0] : case_[1];

    cout << result << "\n";

    return 0;
}