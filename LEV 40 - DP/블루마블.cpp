#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int map[26];
int dp[26];
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int i = 0; i < 13; i++) {
		cin >> map[i];
	}

	dp[0] = map[0];
	dp[1] = map[1];
	dp[2] = map[2];

	for (int i = 3; i <= 26; i++) {
		int a = dp[i - 2];
		int b = dp[i - 3];
		int c = -999;
		if (i % 2 == 0) c = dp[i / 2];

		int maxi = max(a, max(b, c));

		dp[i] = maxi + map[i];
	}
	int maxi = 0;
	for (int i = 13; i < 26; i++) {
		maxi = max(maxi, dp[i]);
	}
	cout << maxi;



	return 0;
}
/*
#include <iostream>
using namespace std;

int map[50];
int acc[50];
int maxim;

void write(int index, int value)
{
if (index >= 12 && maxim < value) maxim = value;
if (acc[index] < value) acc[index] = value;
}

int main()
{
for (int i = 0; i < 12; i++) {
cin >> map[i];
acc[i] = -99999;
}

int a, b, c;
acc[0] = map[0];

for (int i = 0; i < 12; i++) {
write(i + 2, acc[i] + map[i + 2]);
write(i + 3, acc[i] + map[i + 3]);
write(i * 2, acc[i] + map[i * 2]);
}

cout << maxim;

return 0;
}
*/