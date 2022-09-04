#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
int n, m;
int cards[40];
int mini = 21e8;
vector<int> path;
vector<int> result;

int used[40];

void run(int lev, int mul) {

	if (lev == m) {
		if (mini > mul) {
			mini = mul;
			for (int i = 0; i < m; i++) {
				result[i] = path[i];
			}
		}
		return;

	}

	for (int i = 0; i < n; i++) {
		if (used[i] == 1) continue;
		path[lev] = cards[i];
		used[i] = 1;
		run(lev + 1, mul*cards[i]);
		path[lev] = 0;
		used[i] = 0;
	}
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	path.resize(m);
	result.resize(m);
	run(0, 1);

	sort(result.begin(), result.end());

	for (int i = 0; i < m; i++) {
		cout << result[i] << " ";
	}




	return 0;
}

/*

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int> deck;
int n, m;
int minGop = 21e8;

int path[100];
int minPath[100];

void back(int level, int start, int gop) {
if (level == m) {
if (minGop > gop) {
minGop = gop;
memcpy(minPath, path, 100 * 4); //int : 4 Byte x 100ĭ
}
return;
}

for (int i = start; i < n; i++) {
path[level] = deck[i];
back(level + 1, i + 1, gop * deck[i]);
path[level] = 0;
}
}

int main() {
cin >> n >> m;

for (int i = 0; i < n; i++) {
int a;
cin >> a;
deck.push_back(a);
}

sort(deck.begin(), deck.end());

back(0, 0, 1);

for (int i = 0; i < m; i++) {
cout << minPath[i] << " ";
}

return 0;
}
*/