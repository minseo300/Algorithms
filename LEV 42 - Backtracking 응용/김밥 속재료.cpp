#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

string input;
char path[4];
void run(int lev) {
	if (lev == 3) {
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < input.length(); i++) {
		int index = input.find(path[lev - 1]);
		if (lev>0&&input.find(path[lev - 1]) > i) continue;
		path[lev] = input[i];
		run(lev + 1);
		path[lev] = '\0';
	}
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> input;
	run(0);
	return 0;
}
/*
#include <iostream>
#include <string>
using namespace std;

string str;
char path[10];

void run(int level, int start)
{
if (level == 3) {
cout << path << endl;
return;
}

for (int i = start; i < str.length(); i++) {
path[level] = str[i];
run(level + 1, i);
path[level] = 0;
}
}

int main()
{
cin >> str;
run(0, 0);

return 0;
}
*/

