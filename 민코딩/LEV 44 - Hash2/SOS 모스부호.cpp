#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;

string mos[5] = { "1011","0011","1111","0000","1100" };
string input[5];
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int i = 0; i < 5; i++) {
		cin >> input[i];
	}

	unordered_map<string, int> m;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <=1; j++) {
			string substr = input[i].substr(j, 4);
			int d = 1;
			for (int k = 0; k < 5; k++) {
				if (substr == mos[k]) {
					if (m.count(mos[k]) == 0) m[mos[k]] = 1;
				}
			}
		}
	}

	if (m.size() > 0) cout << "yes";
	else cout << "no";
	
	return 0;
}
/*

#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string, bool> map;
string lst[5] = {
"1011","0011","1111","0000","1100"
};
int main() {
map["1011"] = true;
map["0011"] = true;
map["1111"] = true;
map["0000"] = true;
map["1100"] = true;

string signal[5];
for (int i = 0; i < 5; i++) {
cin >> signal[i];
}

int flag = 0;
for (int y = 0; y < 5; y++) {
string a = signal[y].substr(0, 4);
string b = signal[y].substr(1, 4);
if (map.count(a) > 0 || map.count(b) > 0) {
flag = 1;
break;
}
}
if (flag) {
cout << "yes";
}
else {
cout << "no";
}
}
*/