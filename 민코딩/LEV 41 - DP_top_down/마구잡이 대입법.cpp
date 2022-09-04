#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int cnt = 0;
int n;
int path[10];
void sumCount(int lev) {
	if (lev == n) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += path[i];
		}
		if (sum == 7) cnt++;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		path[lev] = i;
		sumCount(lev + 1);
		path[lev] = 0;
	}


}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> n;
	
	sumCount(0);
	cout << cnt;
	return 0;
}


