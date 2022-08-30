#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int total;
int mini=21e8;
int coins[3] = { 10,40,60 };
void run(int lev,int sum) {
	if (sum > total) return;

	if (sum == total) {
		if (mini > lev) mini = lev;
		return;
	}
	
	
	for (int i = 0; i < 3; i++) {
		run(lev + 1, sum + coins[i]);
	}


}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> total;

	run(0,0);
	cout << mini;

	return 0;
}

