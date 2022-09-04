#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;


int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	
	int input;
	cin >> input;
	int cnt = 0;
	int coins[4] = { 500,100,50,10 };

	for (int i = 0; i < 4; i++) {
		cnt += input / coins[i];
		input = input % coins[i];
	}
	cout << cnt;
	
	
	
	
	return 0;
}