#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int products[7] = { 15,20,44,22,55,16,45 };
string input;
int n;
vector<int> prices;
int path[7];
int maxi = -21e8;
int used[7];
void run(int lev, int sum) {

	if (lev == input.length() - n) {
		if (sum > maxi&&sum%10==0) maxi = sum;
		return;
	}

	for (int i = 0; i < input.length(); i++) {
		if (used[i] == 1) continue;

		path[lev] = products[input[i] - 'a'];
		used[i] = 1;
		run(lev + 1, sum + path[lev]);
		path[lev] = 0;
		used[i] = 0;
	}
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> input;
	cin >> n;
	prices.resize(n);

	run(0, 0);
	cout << maxi;
	return 0;
}
