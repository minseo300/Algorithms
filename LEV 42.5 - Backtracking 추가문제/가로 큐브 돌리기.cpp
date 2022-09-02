#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


int n;
int map[5][5];
int maxi = -21e8;
void run(int lev) {
	if (lev == n) {
		int mul = 1;
		for (int x = 0; x < n; x++) {
			int sum = 0;
			for (int y = 0; y < n; y++) {
				sum += map[y][x];
			}
			mul *= sum;
		}
		if (mul > maxi) maxi = mul;
		return;
	}

	for (int i = 0; i < n; i++) {
		run(lev + 1);
		int line[5];
		for (int j = 0; j < n; j++) {
			if (j == 0) line[j] = map[lev][n - 1];
			else line[j] = map[lev][j - 1];
		}
		for (int j = 0; j < n; j++) {
			map[lev][j] = line[j];
		}
	}
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];

		}
	}

	run(0);
	cout << maxi<<"점";
	return 0;
}

/*
#include <iostream>
using namespace std;

int map[10][10];
int n;

int maxValue;

void input()
{
cin >> n;
for (int y = 0; y < n; y++) {
for (int x = 0; x < n; x++) {
cin >> map[y][x];
}
}
}

void spin(int line)
{
int backup = map[line][n - 1];
for (int i = n - 1; i >= 1; i--) {
map[line][i] = map[line][i - 1];
}
map[line][0] = backup;
}

int cal()
{
int sum[10] = { 0 };
int gop = 1;

for (int x = 0; x < n; x++) {
for (int y = 0; y < n; y++) {
sum[x] += map[y][x];
}
gop *= sum[x];
}

return gop;
}

void run(int level)
{
if (level == n) {
int ret = cal();
if (ret > maxValue) {
maxValue = ret;
}
return;
}

//한 라인을 n번 돌리면 원상복구 완료된다.
for (int i = 0; i < n; i++) {
spin(level);
run(level + 1);
}
}

int main()
{
input();
run(0);

cout << maxValue << "점";

return 0;
}
*/