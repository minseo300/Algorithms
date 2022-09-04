#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	for (int i = 0; i < 4; i++) {
		int n;
		cin >> n;

		q.push(n);
	}
	int total = 0;
	while (!q.empty()) {
		int time = q.top();
		q.pop();

		total += time * q.size();
	}

	cout << total;
	
	
	
	return 0;
}