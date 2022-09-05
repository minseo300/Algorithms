#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;
unordered_map<char, int> m;
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	string input;
	cin >> input;

	for (char c = 'A'; c <= 'F'; c++) {
		m[c] = 0;
	}

	for (int i = 0; i < input.length(); i++) {
		if (input[i] > 90) input[i] = input[i] - 32;
		m[input[i]] += 1;
	}

	for (char ch = 'A'; ch <= 'F'; ch++) {
	
		cout << ch << ":" << m[ch] << "\n";
	}
	return 0;
}

/*
#include<iostream>
#include<unordered_map>
using namespace std;


int main() {
unordered_map<char, int> map;
string str;
cin >> str;

for (int i = 0; i < str.length(); i++) {
if ('a' <= str[i] && str[i] <= 'z') {
str[i] = str[i] - 'a' + 'A';
}
}

for (int i = 0; i < str.length(); i++) {
if (map.count(str[i]) == 0) {
map[str[i]] = 1;
}
else {
map[str[i]] ++;
}
}
for (char ch = 'A'; ch <= 'F'; ch++) {
cout << ch << ":" << map[ch] << "\n";
}


}
*/