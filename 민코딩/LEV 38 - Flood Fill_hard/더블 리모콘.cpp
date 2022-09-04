#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int S, D;
struct Node {
	int n, lev; // 현재 위치, 횟수
};
queue<Node> q;
int used[100001];
void push(int n, int lev) {
	if (n < 0 || n>100000) return;
	if (used[n] == 1) return;

	used[n] = 1;
	q.push({ n,lev });
}
int bfs() {

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (now.n == D) return now.lev;

		push(now.n + 1, now.lev + 1);
		push(now.n - 1, now.lev + 1);
		push(now.n * 2, now.lev + 1);
		push(now.n / 2, now.lev + 1);
	}
	return 0;
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> S;
	cin >> D;

	q.push({ S,0 });
	used[S] = 1;

	int answer = bfs();
	cout << answer;

	return 0;
}