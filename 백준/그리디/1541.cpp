#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nums;
int final[50];
int main()
{
    freopen("input.txt", "r", stdin);
    string input;
    cin >> input;
    int start = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            string num = input.substr(start, i - start);
            start = i + 1;
            nums.push_back(stoi(num));
            if (input[i] == '-')
                nums.push_back(-1);
            else if (input[i] == '+')
                nums.push_back(-2);
        }
    }
    nums.push_back(stoi(input.substr(start, input.length() - start)));
    int box = nums[0];
    start = 0;
    int result = 0;
    for (int i = 1; i < nums.size(); i = i + 2)
    {
        if (nums[i] == -1)
        {
            final[start++] = box;
            box = nums[i + 1];
        }
        else if (nums[i] == -2)
        {
            box += nums[i + 1];
        }
    }
    final[start++] = box;
    for (int i = 0; i < start; i++)
    {
        if (i == 0)
            result += final[i];
        else
            result -= final[i];
    }

    cout << result << "\n";

    return 0;
}