#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<cmath>
using namespace std;
struct Node {
	char c;
	int id;
};
unordered_map<int,Node> m;
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	m[0] = { 'A',21 };
	m[1] = { 'E',15};
	m[2] = { 'E',6 };
	m[3] = { 'A',15 };
	m[4] = { 'E',34 };
	m[5] = { 'B',32 };
	m[6] = { 'C',35 };
	m[7] = { 'C',36 };
	m[8] = { 'D',14 };
	m[9] = { 'A',3 };
	
	char input;
	cin >> input;
	for (int i = 0; i < 10; i++) {
		if (m[i].c == input) cout << m[i].id << " ";
	}


	return 0;
}

