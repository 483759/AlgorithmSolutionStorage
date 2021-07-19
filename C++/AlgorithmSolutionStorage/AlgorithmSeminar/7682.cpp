#include <iostream>
#include <string>
#include <map>
#define board(i,j) str[(i)*3+j]
using namespace std;

map<string, bool> m;
string str = ".........";
bool ans = false;

bool finish() {
	for (int i = 0; i < 3; i++) {
		int cnt[2] = { 0,0 };
		char c[2] = { board(i, 0), board(0, i) };
		for (int j = 0; j < 3; j++) {
			if (board(i, j) == '.')cnt[0] = 0;
			else if (board(i, j) == c[0])cnt[0]++;
			else cnt[0] = 1;
			if (board(j, i) == '.')cnt[1] = 0;
			else if (board(j, i) == c[1])cnt[1]++;
			else cnt[1] = 1;
		}
		if (cnt[0] == 3 || cnt[1] == 3)
			return true;
	}
	if (board(0, 0) != '.' && (board(0, 0) == board(1, 1)) && (board(1, 1) == board(2, 2)))
		return true;
	if (board(0, 2) != '.' && (board(0, 2) == board(1, 1)) && (board(1, 1) == board(2, 0)))
		return true;
	return false;
}

void func(char turn, int dep) {
	if (finish() || dep == 9) {
		m.insert(make_pair(str, true));
		return;
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board(i, j) == '.') {
				board(i, j) = turn;
				if (turn == 'X')func('O', dep + 1);
				if (turn == 'O')func('X', dep + 1);
				board(i, j) = '.';
			}
}

int main() {
	freopen("input.txt", "r", stdin);
	func('X', 0);
	while (1) {
		cin >> str;
		if (str == "end")break;

		if (m.find(str) != m.end())cout << "valid\n";
		else cout << "invalid\n";

	}
	return 0;
}