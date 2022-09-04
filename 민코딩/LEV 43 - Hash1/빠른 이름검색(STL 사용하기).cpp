#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;
unordered_map<string,int> m;
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	m["POP"] = 1;
	m["TOM"] = 1;
	m["MC"] = 1;
	m["JASON"] = 1;
	m["KFC"] = 1;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;

		if (m.count(name) == 0) cout << "no\n";
		else cout << "yes\n";
	}
	
	return 0;
}


