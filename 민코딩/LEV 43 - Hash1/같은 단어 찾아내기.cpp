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

	string input = "BOBOOBOBOBOBBM";
	for (int i = 0; i <= input.length() - 3; i++) {
		string sub = input.substr(i, 3);
		m[sub] += 1;
		int d = 1;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		cout << m[word] << "\n";
	}
	
	return 0;
}


/*
#include<iostream>
#include<unordered_map>
using namespace std;


int main() {
string str = "BOBOOBOBOBOBBM";

// set to map
unordered_map<string, int> map;
for (int i = 0; i <= str.length() - 3; i++) {
string key = str.substr(i, 3);
if (map.count(key) == 0) {
map[key] = 1;
}
else {
map[key] ++;
}
}

int N;
cin >> N;
for (int i = 0; i < N; i++) {
string key;
cin >> key;
if (map.count(key) == 0) {
cout << 0 << "\n";
}
else {
cout << map[key] << "\n";
}
}
}


*/