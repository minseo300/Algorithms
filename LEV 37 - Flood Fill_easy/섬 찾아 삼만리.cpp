#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int N, M;
int map[100][100];
struct Node {
	int y, x,lev;
};
queue<Node> q;

int direct[4][2] = {
	-1,0,
	0,-1,
	0,1,
	1,0
};
void bfs(int sy, int sx) {
	
	q.push({ sy,sx,0 });
	map[sy][sx] = 0;
	int cnt = 0;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + direct[i][0];
			int dx = now.x + direct[i][1];

			if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue;
			if (map[dy][dx] == 0) continue;
			
			map[dy][dx] = 0;
			q.push({ dy,dx,now.lev + 1 });
			cnt = now.lev + 1;
		}
	}
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 0) continue;
	
			bfs(y, x);
			cnt++;
		
		}
	}
	
	cout << cnt;
}