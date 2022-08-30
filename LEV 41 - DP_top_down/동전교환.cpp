#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int T, n;
vector<int> coins;
int memo[3002];
int getCoinCount(int total) {
	if (total == 0) return 0;
	if (total < 0) return 21e8;
	if (memo[total] > 0) return memo[total];

	vector<int> coin(n);
	for (int i = 0; i < n; i++) {
		coin[i] = getCoinCount(total - coins[i]) + 1;
	}

	int min = *min_element(coin.begin(), coin.end());

	memo[total] = min;
	return min;
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> T >> n;
	coins.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	int result = getCoinCount(T);
	if (result >= 21e8) cout << "impossible";
	else cout << result;
	

	return 0;
}


