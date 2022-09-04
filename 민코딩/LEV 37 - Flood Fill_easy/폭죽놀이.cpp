#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int map[4][5];
int used[4][5];
struct Node {
	int y, x, lev;
};
int answer;
queue<Node> q;
int direct[8][2] = {
	-1,-1,
	-1,0,
	-1,1,
	0,-1,
	0,1,
	1,-1,
	1,0,
	1,1
};
void firework(int y, int x,int lev) {
	
	for (int i = 0; i < 8; i++) {
		int dy = y + direct[i][0];
		int dx = x + direct[i][1];

		if (dy < 0 || dx < 0 || dy >= 4 || dx >= 5) continue;
		if (used[dy][dx] == 1) continue;

		used[dy][dx] = 1;
		q.push({ dy,dx,lev + 1 });
		answer = lev + 1;
	}
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			if (map[y][x] == 1) {
				firework(y, x,0);
			}
		}
	}

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		firework(now.y, now.x, now.lev);
	}

	cout << answer;

}