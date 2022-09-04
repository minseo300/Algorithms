#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int H, W;
int map[1000][1000];
int used[1000][1000];
int sy, sx;
struct Node {
	int y, x, lev;
};
queue<Node> q;
int direct[4][2] = {
	-1,0,
	0,-1,
	0,1,
	1,0
};
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int answer;

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> map[y][x];
		}
	}
	cin >> sy >> sx;
	q.push({ sy,sx,0 });
	used[sy][sx] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + direct[i][0];
			int dx = now.x + direct[i][1];

			if (dy < 0 || dx < 0 || dy >= H || dx >= W) continue;
			if (map[dy][dx] == 1) continue;
			if (used[dy][dx] == 1) continue;

			used[dy][dx] = 1;
			q.push({ dy,dx,now.lev + 1 });
			answer = now.lev + 1;
		}
	}
	cout << answer << "\n";
}