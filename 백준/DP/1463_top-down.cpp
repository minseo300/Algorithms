#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
vector<int> dp;
int top_down(int now) {
	if (now == 1) return 0;
	if (dp[now] !=-1) return dp[now];

	dp[now] = top_down(now - 1) + 1;

	if (now % 2 == 0) {
		int temp = top_down(now / 2) + 1;
		if (dp[now] > temp) dp[now] = temp;
	}

	if (now % 3 == 0) {
		int temp = top_down(now / 3) + 1;
		if (dp[now] > temp) dp[now] = temp;
	}
	
	return dp[now];
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n;
    dp.resize(n+1,-1);
    cout<<top_down(n)<<"\n";
    return 0;
}