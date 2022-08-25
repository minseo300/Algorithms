#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

char map[20][20];
int N, M; // 세로, 가로
vector<vector<int>> used;
struct Node {
	int y, x, lev;
};
void usedInit() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			used[y][x] = 0;
		}
	}
}
int direct[4][2] = {
	-1,0,
	0,-1,
	0,1,
	1,0
};
Node bfs(int sy, int sx, int lev,char tar) {
	queue<Node> q; // queue를 초기화하지 않으면 queue에 이전에 했던 게 남아,,,
	usedInit();
	q.push({ sy,sx,lev });
	used[sy][sx] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + direct[i][0];
			int dx = now.x + direct[i][1];

			if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue;
			if (map[dy][dx] == 'x') continue;
			if (used[dy][dx] == 1) continue;

			if (map[dy][dx] == tar) {
				return { dy,dx,now.lev + 1 };
			}
			used[dy][dx] = 1;
			q.push({ dy,dx,now.lev + 1 });
		}

	}
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> N >> M;
	int cy, cx;
	used.assign(N, vector<int>(M, 0));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'S') {
				cy = y;
				cx = x;
			}
		}
	}

	Node toCheese = bfs(cy, cx, 0,'C');
	Node toFriend = bfs(toCheese.y, toCheese.x, 0, 'D');
	
	cout << toCheese.lev + toFriend.lev;
	
}