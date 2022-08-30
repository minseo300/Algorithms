#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

string exs[5] = { "BTS","SBS","BS","CBS","SES" };
string input;
string path[5];
int mini = 6;
int counting(int lev) {
	string output;
	int count = 0;
	for (int j = 0; j < lev; j++) {
		output += path[j];
	}
	if (output.compare(input) == 0) count = lev + 1;

	return count;
}
void run(int lev) {
	if (lev == 5) {
		return;
	}

	for (int i = 0; i < 5; i++) {
		path[lev] = exs[i];
		string output;
		
		for (int j = 0; j <= lev; j++) {
			output.append(path[j]);
		}
		if (output.compare(input) == 0) {
			int count = lev + 1;
			if (count < mini) mini = count;
		}
		run(lev + 1);
		path[lev] = "";
	}
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> input;

	run(0);

	cout << mini;


	return 0;
}

/*

#include <iostream>
#include <string>
using namespace std;

string vect[5] = { "BTS", "SBS", "BS", "CBS", "SES" };
string target;
int minim = 21e8;

void run(int level, string sum)
{
if (target.length() < sum.length()) return;
if (sum == target) {
if (minim > level) minim = level;
return;
}

for (int i = 0; i < 5; i++) {
int n = sum.length();
if (vect[i][0] == target[n]) {
run(level + 1, sum + vect[i]);
}
}
}

int main()
{
cin >> target;
run(0, "");
cout << minim;

return 0;
}
*/