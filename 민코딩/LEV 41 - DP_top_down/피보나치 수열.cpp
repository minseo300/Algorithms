#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;


int n;
int memo[100] = { 0,1, };
int fibo(int n) {

	if (memo[n] > 0) return memo[n];
	if (n == 1) return 1;
	if (n == 0) return 0;

	int a = fibo(n - 1);
	int b = fibo(n - 2);

	memo[n] = a + b;
	return a + b;
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> n;

	cout << fibo(n-1);


	return 0;
}


