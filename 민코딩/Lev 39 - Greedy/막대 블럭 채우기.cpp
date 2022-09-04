#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int n;
int home = 100;
priority_queue<int,vector<int>,greater<int>> q;
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int block;
		cin >> block;

		q.push(block);
	}
	int cnt = 0;
	while (!q.empty()) {
		
		int now = q.top();
		q.pop();

		if (home < now) continue;

		home -= now;
		cnt++;
	}
	
	cout << cnt;
	return 0;
}