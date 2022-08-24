#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct Node {
	int y, x;
	int price;
};
int N;
int gy, gx;
int map[1000][1000];
const int M = 21e8;
int result[1000][1000];
int tired = 0;
priority_queue<Node> q;
int dir[4][2] = {
	0,-1,
	1,0,
	0,1,
	-1,0
};
bool operator<(Node v, Node t) {
	return t.price < v.price;
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> gy >> gx;
	cin >> N;
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			result[y][x] = M;
		}
	}


	q.push({ gy,gx,map[gy][gx] });

	while (!q.empty()) {
		Node now = q.top();
		q.pop();

		if (map[now.y][now.x] == 21e8) continue;
		map[now.y][now.x] = 21e8;

		if (result[now.y][now.x] < now.price) continue;

		for (int d = 0; d < 4; d++) {
			int dy = now.y + dir[d][0];
			int dx = now.x + dir[d][1];

			if (dy < 0 || dx < 0 || dy >= N || dx >= N||map[dy][dx]==-1||map[dy][dx]==M) continue;

			Node next = { dy,dx,map[dy][dx] };
			int total = now.price + next.price;

			if (total < result[next.y][next.x]) {
				result[next.y][next.x] = total;

				q.push({ next.y,next.x,total });
			}
		}

		tired = now.price;

	}
	cout << tired << "\n";
}