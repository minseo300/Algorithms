#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int map[4][4];
int used[4][4];
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
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}

	q.push({ 0,0});
	used[0][0] = 1;
	int cnt = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + direct[i][0];
			int dx = now.x + direct[i][1];

			if (dy < 0 || dx < 0 || dy >= 4 || dx >= 4) continue;
			if (map[dy][dx] == 0) continue;
			if (used[dy][dx] == 1) continue;
			
			used[dy][dx] = 1;
			q.push({ dy,dx });
			cnt++;
		}
	}
	cout << cnt;
}