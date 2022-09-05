#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;

int h, w;
string map[1000];
int pn;
string pattern[20];
struct Node {
	int y, x;
};
struct p {
	vector<string> strs;
};
unordered_map<int, Node> mm;
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);


	cin >> h >> w;
	for (int y = 0; y < h; y++) {
		cin >> map[y];
	}

	cin >> pn;
	for (int y = 0; y < pn; y++) {
		cin >> pattern[y];
	}

	int k = 0;
	for (int y = 0; y <= h - pn; y++) {
		int sy = y;
		for (int x = 0; x <= w - pn; x++) {
			int sx = x;
			int cnt = 0;
			for (int i = 0; i < pn; i++) {
				for (int j = 0; j < pn; j++) {
					if (map[y + i][x + j] == pattern[i][j]) cnt++;
				}
			}
			if (cnt == pn * pn) mm.insert({ k++,{sy,sx} });
		}
	}

	for (int i = 0; i < mm.size(); i++) {
		cout << mm[i].y << "," << mm[i].x << "\n";
	}
	

	return 0;
}

/*
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int h;
int w;
int map[1100][1100];
char tar[30][30];
int pn;

struct Node {
int y, x;
};

unordered_map<string, vector<Node>> m;

void init() {
for (int y = 0; y <= h - 3; y++) {
for (int x = 0; x <= w - 3; x++) {

string temp;
for (int dy = 0; dy < 3; dy++) {
for (int dx = 0; dx < 3; dx++) {
temp += map[y + dy][x + dx];
}
}

m[temp].push_back({ y, x });
}
}
}

int isSame(int dy, int dx)
{
if (dy + pn > w) return 0;
if (dx + pn > h) return 0;

for (int y = 0; y < pn; y++) {
for (int x = 0; x < pn; x++) {
if (map[dy + y][dx + x] != tar[y][x]) return 0;
}
}
return 1;
}

int main()
{
//freopen("Text.txt", "r", stdin);
cin >> h >> w;
char buf[1100] = { 0 };
for (int y = 0; y < h; y++) {
cin >> buf;
for (int x = 0; x < w; x++) {
map[y][x] = buf[x];
}
}

init();

cin >> pn;

for (int y = 0; y < pn; y++) {
cin >> buf;
for (int x = 0; x < pn; x++) {
tar[y][x] = buf[x];
}
}

string st;
for (int y = 0; y < 3; y++) {
for (int x = 0; x < 3; x++) {
st += tar[y][x];
}
}

for (int i = 0; i < m[st].size(); i++) {
if (isSame(m[st][i].y, m[st][i].x) == 1) {
cout << m[st][i].y << "," << m[st][i].x << "\n";
}
}


return 0;
}

*/