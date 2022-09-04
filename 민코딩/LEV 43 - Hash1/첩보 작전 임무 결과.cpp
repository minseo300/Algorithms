#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;

unordered_map<char,int> m;
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	m['B'] = 10;
	m['T'] = 15;
	m['S'] = 12;
	m['G'] = 15;
	m['O'] = 14;
	m['D'] = 13;
	m['Z'] = 16;

	char code;
	cin >> code;
	cout << m[code];


	return 0;
}

