#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, K, A, B;
struct Node {
	int n, price;
};
vector<vector<Node>> alist;
priority_queue<Node> pq;
vector<int> result;
bool operator<(Node v, Node t) {
	return t.price < v.price;
}
int dijkstra(int start,int end) {
	int visited[1001] = { 0, };
	pq.push({ start,0 });

	result.assign(N + 1, 21e8);
	result[start] = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (visited[now.n] == 1) continue;
		visited[now.n] = 1;

		if (result[now.n] < now.price) continue;

		for (int i = 0; i < alist[now.n].size(); i++) {
			Node next = alist[now.n][i];
			int total = now.price + next.price;

			if (result[next.n] > total) {
				result[next.n] = total;
				pq.push({ next.n,total });
			}
		}
	}
	return result[end];

}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M >> K;
	cin >> A >> B;
	alist.assign(N+1, vector<Node>());
	for (int i = 0; i < M; i++) {
		int f, t, c;
		cin >> f >> t >> c;
		alist[f].push_back({ t,c });
		alist[t].push_back({ f,c });
	}

	for (int i = 0; i <= K; i++) {
		int total_price=dijkstra(A, B);
		cout << total_price<<"\n";

		int added;
		cin >> added;
		for (int i = 0; i < alist.size(); i++) {
			for (int j = 0; j < alist[i].size(); j++) {
				alist[i][j].price += added;
			}
		}
	}

}