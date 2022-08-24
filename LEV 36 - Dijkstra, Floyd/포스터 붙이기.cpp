#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int C, P, K, A, B;
struct Node {
	int n, price;
};
bool operator<(Node v, Node t) {
	return t.price < v.price;
}
vector<vector<Node>> list;
vector<int> result;
vector<int> result2;
vector<int> visited;
priority_queue<Node> q;

int dijkstra(int start,int *stopover) {
	q.push({ start,0 });
	result.assign(P + 1, 21e8);
	visited.assign(P + 1, 0);

	result[start] = 0;

	while (!q.empty()) {
		Node now = q.top();
		q.pop();

		if (visited[now.n] == 1) continue;
		visited[now.n] = 1;

		if (result[now.n] < now.price) continue;

		for (int i = 0; i < list[now.n].size(); i++) {
			Node next = list[now.n][i];
			int total = now.price + next.price;

			if (result[next.n] > total) {
				result[next.n] = total;
				q.push({ next.n,total });
			}
		}

	}
	if (result[A] == 0) {
		return result[B];
	}
	else if (result[B] == 0) {
		return result[A];
	}
	if (result[A] > result[B]) {
		*stopover = B;
		return result[B];
	}
	else {
		*stopover = A;
		return result[A];
	}

}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> C >> P >> K >> A >> B;
	
	list.assign(P + 1, vector<Node>());
	result2.assign(P + 1, 21e8);
	for (int i = 0; i < C; i++) {
		int P1, P2, D;
		cin >> P1 >> P2 >> D;

		list[P1].push_back({ P2,D });
		list[P2].push_back({ P1,D });
	}

	int dis = 0, stopover;
	
	dis += dijkstra(K, &stopover);
	dis += dijkstra(stopover, &stopover);

	cout<<dis<<"\n";
}