#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int n;
int cnt = 0;
void run(int lev,int sum) {
	if (lev == n) {
		if (sum == 10) cnt++;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		run(lev + 1, sum + i);
	}
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> n;
	
	run(0,0);
	cout << cnt;

	return 0;
}

