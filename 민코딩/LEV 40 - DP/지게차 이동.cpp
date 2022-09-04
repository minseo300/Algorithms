#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
struct Node {
	int y, x, tired;
};
int map[4][4];
Node dp[4][4];
int dir[4][4];
const int M = 21e8;
void init() {
	for (int i = 2; i >= 0; i--) {
		dp[3][i] = { 3,i + 1,map[3][i] + dp[3][i + 1].tired };
		dp[i][3] = { i + 1,3,map[i][3] + dp[i + 1][3].tired };
	}
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}
	init();

	for (int y = 2; y >= 0; y--) {
		for (int x = 2; x >= 0; x--) {
			// 오른쪽이 아래보다 작거나 같으면
			if (dp[y][x + 1].tired <= dp[y + 1][x].tired) {
				dp[y][x] = { y,x + 1,map[y][x] + dp[y][x + 1].tired };
			}
			else {
				dp[y][x] = { y + 1,x,map[y][x] + dp[y + 1][x].tired };
			}
		}
	}
	int by = 0;
	int bx = 0;
	while (1) {
		cout << by << "," << bx << "\n";
		if (by == 3 && bx == 3) break;
		int y = by;
		int x = bx;
		by = dp[y][x].y;
		bx = dp[y][x].x;

	}
	return 0;
}