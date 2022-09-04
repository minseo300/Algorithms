#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int n;
vector<int> map;
struct Node {
	int index, num;
};
int rest;
int direct[2] = { -1,1 };
int maxi = -21e8;
Node path[8];
int used[8];
int by[8];
int result[8];
int ex[8];
int maxiLev;
void init(int index) {
	used[index] = 0;
	path[index].index = 21e8;
	path[index].num = 0;
	rest++;
	for (int i = 0; i < n; i++) {
		if (by[i] == index) {
			used[i] = 0;
			path[i].index = 21e8;
			path[i].num = 0;
			rest++;
		}
	}
	
}
int compare(Node t, Node v) {
	if (t.index < v.index) return 1;

	return 0;
}
void run(int lev, int score) {
	if (rest == 0) {
		if (maxi < score) {
			maxi = score;
			maxiLev = lev;
			sort(path, path + 8,compare);
			for (int i = 0; i < lev; i++) {
				result[i] = path[i].num;
			}
		}
		
		return;
	}
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (used[i] == 1) continue;

		path[lev].index = i;
		path[lev].num = map[i];
		used[i] = 1;
		for (int d = 0; d < 2; d++) {
			int di = i + direct[d];

			if (di < 0 || di >= n) continue;
			if (used[di] == 1) continue;

			used[di] = 1;
			by[di] = i;
			rest--;
	
		}
		rest--;
		run(lev + 1, score + map[i]);
		int d = 1;
		init(i);
		
	}

}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n;
	map.resize(n);
	rest = n;

	for (int i = 0; i < 8; i++) {
		by[i] = -21e8;
		path[i].index = 21e8;
	}
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		
	}
	run(0,0);
	int d = 1;
	for (int i = 0; i < maxiLev; i++) {
		cout << result[i];
		if (i == maxiLev - 1) cout << "=";
		else cout << "+";
	}
	cout << maxi;
	return 0;
}

/*
#include <iostream>
using namespace std;

int n;
int pan[10];

int used[10];
int history[10];

int maxi;
int maxHistory[10];
int maxLevel;

int isFinish()
{
for (int i = 0; i < n; i++) {
if (used[i] == 0) return 0;
}
return 1;
}

void run(int level)
{
if (isFinish() == 1) {

int sum = 0;
for (int i = 0; i < level; i++) {
sum += history[i];
}

if (sum > maxi) {
maxi = sum;
maxLevel = level;
for (int i = 0; i < level; i++) {
maxHistory[i] = history[i];
}
}

return;
}

for (int i = 0; i < n; i++) {
if (used[i] == 0) {
used[i]++;
if (i + 1 < n) used[i + 1]++;
if (i - 1 >= 0) used[i - 1]++;

history[level] = pan[i];
run(level + 1);
history[level] = 0;

used[i]--;
if (i + 1 < n) used[i + 1]--;
if (i - 1 >= 0) used[i - 1]--;
}
}
}

int main()
{
cin >> n;
for (int i = 0; i < n; i++) {
cin >> pan[i];
}

run(0);

int i = 0;
for (i = 0; i < maxLevel - 1; i++) {
cout << maxHistory[i] << "+";
}
cout << maxHistory[i] << "=";
cout << maxi;

return 0;
}
*/