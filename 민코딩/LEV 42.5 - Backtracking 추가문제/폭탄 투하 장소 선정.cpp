#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


string map[4];
int n;
struct Node {
	int y, x;
	char c;
};

struct Use {
	int by, bx;
	int used;
};
Node bombs[9];
vector<char> result;
Node path[9];
int maxi = -21e8;
int bombIndex = 0;
Use used[4][4];
Node checked[16];
int direct[5][2] = {
	-1,0,
	0,-1,
	0,1,
	0,0,
	1,0
};
void init(Node now) {
	for (int d = 0; d < 5; d++) {
		int dy = now.y + direct[d][0];
		int dx = now.x + direct[d][1];

		if (dy < 0 || dx < 0 || dy >= 4 || dx >= 4) continue;
		
		if(used[dy][dx].bx==now.x&&used[dy][dx].by==now.y) used[dy][dx].used = 0;
	}

}
void run(int lev,int cnt) {
	if (lev == n) {
		if (maxi < cnt) {
			maxi = cnt;
			
			for (int i = 0; i < n; i++) {
				result[i]=map[path[i].y][path[i].x];
			}
		}

		return;
	}

	for (int i = 0; i < bombIndex; i++) {
		Node now = bombs[i];
		if (used[now.y][now.x].used == 1) continue;
		used[now.y][now.x].used = 1;

		path[lev] = { now.y,now.x,now.c};
		int bomb = 1, checkedIndex = 0;
		for (int d = 0; d < 5; d++) {
			int dy = now.y + direct[d][0];
			int dx = now.x + direct[d][1];

			if (dy < 0 || dx < 0 || dy >= 4 || dx >= 4) continue;
			if (map[dy][dx] == '_') continue;
			if (used[dy][dx].used == 1) continue;

			used[dy][dx].used = 1;
			used[dy][dx].by = now.y;
			used[dy][dx].bx = now.x;
			bomb++;
		}
		
		
		int j = 1;
		run(lev + 1, cnt + bomb);
		used[now.y][now.x].used = 0;
		init(now);
		
		//init(now);
		//used[now.y][now.x] = 0;
		//init(lev);
	}
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int i = 0; i < 4; i++) {
		cin >> map[i];
	}
	cin >> n;

	result.resize(n);

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (map[y][x] == '_') continue;

			bombs[bombIndex++] = { y,x,map[y][x]};
		}
	}

	run(0, 0);
	
	sort(result.begin(),result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}

/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char map[4][5];
char path[20];

int maxi;

char maxPath[20];

int bn;

int boom(int dy, int dx) {
int direct[5][2] = { 0,0, 1,0, -1,0, 0,1, 0,-1 };
int cnt = 0;

for (int t = 0; t < 5; t++) {
int ny = dy + direct[t][0];
int nx = dx + direct[t][1];
if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
if (map[ny][nx] != '_') cnt++;
map[ny][nx] = '_';
}
return cnt;
}

void run(int level, int cnt) {

if (level == bn) {
if (maxi < cnt) {
maxi = cnt;
memcpy(maxPath, path, 20);
}

return;
}

char backup[4][5];
memcpy(backup, map, 4 * 5);

for (int y = 0; y < 4; y++) {
for (int x = 0; x < 4; x++) {
if (map[y][x] == '_') continue;

path[level] = map[y][x];
int ret = boom(y, x);
run(level + 1, cnt + ret);
path[level] = 0;

//원상복구
memcpy(map, backup, 4 * 5);
}
}
}

int main() {
for (int i = 0; i < 4; i++) {
cin >> map[i];
}
cin >> bn;

run(0, 0);

sort(maxPath, maxPath + bn);
for (int i = 0; i < bn; i++) {
cout << maxPath[i] << " ";
}

return 0;
}
*/