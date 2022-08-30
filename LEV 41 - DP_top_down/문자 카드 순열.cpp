#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

char cards[3];
char path[3];
int used[3];
void run(int lev) {
	if (lev == 3) {
		for (int i = 0; i < 3; i++) {
			cout << path[i];
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (used[i] == 1) continue;
		path[lev] = cards[i];
		used[i] = 1;
		run(lev + 1);
		used[i] = 0;
		path[lev] = '\0';
	}

}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	for (int i = 0; i < 3; i++) {
		cin >> cards[i];
	}
	
	run(0);
	return 0;
}


