#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
int n;
struct Block {
	int row, col;
};
struct Node {
	vector<Block> blocks;
};
int fact(int n) {
	int mul = 1;
	if (n == 0) return 1;
	for (int i = n; i > 0; i--) {
		mul *= n--;
	}
	return mul;
}
vector<Node> arr;
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n;

	arr.resize(n + 1);

	vector<Block> zero;
	zero.push_back({ 0,0 });
	arr[0] = { zero };
	vector<Block> one;
	one.push_back({ 1,0 });
	arr[1] = { one };
	for (int i = 2; i <= n; i++) {
		vector<Block> b;
		b.push_back({ arr[i - 1].blocks[0].row + 1,0 });

		for (int j = 0; j < arr[i - 2].blocks.size(); j++) {
			b.push_back({ arr[i - 2].blocks[j].row,arr[i - 2].blocks[j].col + 1 });
		}
		arr[i] = { b };
	}

	int cnt = 0;

	for (int i = 0; i < arr[n].blocks.size(); i++) {
		int denominator = fact(arr[n].blocks[i].col + arr[n].blocks[i].row);
		int r = fact(arr[n].blocks[i].row);
		int c = fact(arr[n].blocks[i].col);

		cnt += denominator / r / c;

	}

	cout << cnt;
	
	return 0;
}
/*
#include <iostream>
using namespace std;

int main()
{
	int vect[100] = { 0, 1, 2 };

	int n;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		vect[i] = vect[i - 2] + vect[i - 1];
	}

	cout << vect[n];

	return 0;
}
*/