#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int map[4][9];
int used[4][9];
struct Node {
	int y, x;
};
int direct[4][2] = {
	-1,0,
	0,-1,
	0,1,
	1,0
};
queue<Node> q;
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> map[y][x];
		}
	}

	int maxCnt = 0, maxNum = 0;
	int cnt = 0, num = 0;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 9; x++) {
			cnt = 1;
			num = map[y][x];
			if (used[y][x] == 1) continue;

			q.push({ y,x });
			used[y][x] = 1;

			while (!q.empty()) {
				Node now = q.front();

				q.pop();

				for (int i = 0; i < 4; i++) {
					int dy = now.y + direct[i][0];
					int dx = now.x + direct[i][1];

					if (dy < 0 || dy >= 4 || dx < 0 || dx >= 9) continue;
					if (used[dy][dx] == 1) continue;

					if (map[dy][dx] != map[now.y][now.x]) continue;

					used[dy][dx] = 1;
					q.push({ dy,dx });
					cnt++;
				}
			}

			if (maxCnt < cnt) {
				maxCnt = cnt;
				maxNum = num;
			}
		}
	}

	cout << maxCnt * maxNum;



	return 0;
}