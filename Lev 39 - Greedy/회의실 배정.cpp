#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int n,cnt;
struct Node {
	int start, end;
};
bool operator<(Node v, Node t) {
	return t.end < v.end;
}
priority_queue<Node> q;
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		q.push({ s,e });
	}
	int end=0;
	while (!q.empty()) {
		Node now = q.top();
		q.pop();

		if (now.start < end) continue;
		
		end = now.end;
		cnt++;
	}
	
	cout << cnt;
	
	
	return 0;
}