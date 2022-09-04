#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int nums[5];
int path[5];
int used[5];
int mini = 21e8, maxi = -21e8;
void run(int lev) {
	if (lev == 5) {
		int result = path[0] * path[1] - path[2] * path[3] + path[4];
		if (result < mini) mini = result;
		if (result > maxi) maxi = result;

		return;
	}

	for (int i = 0; i < 5; i++) {
		if (used[i] == 1) continue;

		path[lev] = nums[i];
		used[i] = 1;
		run(lev + 1);
		path[lev] = 0;
		used[i] = 0;


	}
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	for (int i = 0; i < 5; i++) {
		cin >> nums[i];
	}
	run(0);
	cout << maxi << "\n" << mini;
	return 0;
}

