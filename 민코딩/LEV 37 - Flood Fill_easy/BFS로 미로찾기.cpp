#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node {
	int y, x, lev;
};
int map[4][4] = {
	0,0,0,0,
	1,1,0,1,
	0,0,0,0,
	1,0,1,0
};

int direct[4][2] = {
	-1,0,
	0,-1,
	0,1,
	1,0
};
int sy, sx, ey, ex;
queue<Node> q;
int used[4][4];

int bfs() {
	q.push({ sy,sx,0 });
	used[sy][sx] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + direct[i][0];
			int dx = now.x + direct[i][1];

			if (dy < 0 || dx < 0 || dy >= 4 || dx >= 4) continue;
			if (map[dy][dx] == 1) continue;
			if (used[dy][dx] == 1) continue;

			used[dy][dx] = 1;
			q.push({ dy,dx,now.lev + 1 });
			if (dy == ey && dx == ex) return now.lev + 1;

		}
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	
	cin >> sy >> sx;
	cin >> ey >> ex;

	
	int answer = bfs();
	cout << answer << "ȸ";
	
}