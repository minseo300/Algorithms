#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int n;
vector<int> nums;
int cnt;
string path[10];

string operators[4] = { "!!","#","$","&" };
void run(int lev) {
	if (lev == n - 1) {
		int result=1;
		for (int i = 0; i < lev; i++) {
			if (i == 0) result = nums[0];
			if (path[i] == "!!") {
				result = (result-nums[i+1])*(result + nums[i + 1]);
			}
			else if (path[i] == "#") {
				result = result > nums[i + 1] ? result : nums[i + 1];
			}
			else if (path[i] == "$") {
				result = result * result - nums[i + 1] * nums[i + 1];
			}
			else if (path[i] == "&") {
				result = (result + nums[i + 1])*(result + nums[i + 1]);
			}
		}

		if (result == 100) cnt++;
		int d = 1;
		return;
	}

	for (int i = 0; i < 4; i++) {
		path[lev] = operators[i];
		run(lev + 1);
	}
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	run(0);
	cout << cnt;
	return 0;
}
