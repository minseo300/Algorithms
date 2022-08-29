#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int map[7][3];
int dp[7][3];

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> map[y][x];
			dp[y][x] = -9999;
		}
	}
	dp[0][0] = map[0][0];
	int directX[3] = { -1,0,1 };
	for (int y = 1; y < 7; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[y][x] == 0) continue;
			for (int i = 0; i < 3; i++) {
				int dy = y - 1;
				int dx = x + directX[i];

				if (dx < 0 || dx >= 3) continue;

				if (dp[y][x] < map[y][x] + dp[dy][dx]) {
					dp[y][x] = map[y][x] + dp[dy][dx];
				}
			}
		}
	}

	int maxi = max(dp[6][0], max(dp[6][1], dp[6][2]));

	cout << maxi;


	return 0;
}
