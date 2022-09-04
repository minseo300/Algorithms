#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;
unordered_map<int,string> m;
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	m[1000000005 % 14] = "Sour";
	m[1000000002 % 14] = "Dav";
	m[1000000003 % 14] = "Nica";
	m[1000000006 % 14] = "Timer";
	m[1000000015 % 14] = "Pico";
	m[1000000022 % 14] = "Topisl";
	m[1000000013 % 14] = "Whab";
	m[1000000009 % 14] = "Hap";

	long n;
	cin >> n;
	cout << m[n % 14];


	return 0;
}

/*
#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
unordered_map<string, int> map; // key : string , value : int

map["1000000005"] ++;
map["1000000006"] ++;
map["1000000035"] ++;
map["1000000002"] ++;
map["1000000011"] ++;
map["1000000005"] ++;
map["1000000015"] ++;
map["1000000025"] ++;

string str;
cin >> str;

cout << map[str] << "¸¶¸®";
return 0;
}
*/