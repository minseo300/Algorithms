#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;

int ages[2];
unordered_map<string, int> m;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;
	string output;
	for (int i = 0; i < n; i++) {
		string name;
		int age;
		cin >> name >> age;
		if (m.count(name) == 1) {
			output = name;
			ages[0] = m[name];
			ages[1] = age;
		}
		else {
			m[name] = age;
		}
	}

	sort(ages, ages + 2);
	cout << output << "\n";
	for (int i = 0; i < 2; i++) {
		cout << ages[i] << " ";
	}


	return 0;
}

/*
#include<iostream>
#include<unordered_map>
using namespace std;

int N;
unordered_map<string, int> map;

int main() {
cin >> N;
for (int i = 0; i < N; i++) {
string name;
int age;
cin >> name >> age;
if (map.count(name) == 0) {
map.insert({ name, age });
}
else {
// map[name](기존 key 에 있던 나이) vs age(현재입력된나이)
cout << name << endl;
if (map[name] > age) {
cout << age << " " << map[name];
}
else {
cout << map[name] << " " << age;
}

return 0;
}
}
}
*/