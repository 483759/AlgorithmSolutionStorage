#include <iostream> 
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
using namespace std;

string s, f;
map<string, int> m;
bool visit[2500];

bool safe(int num) {
	return num >= 0 && log2(num) < 11 && !visit[num];
}

int binaryToDecimal(string bs) {
	int num = 0;
	for (int i = 0; i < bs.length(); i++) {
		if (bs[i] == '1') num += pow(2, bs.length() - 1 - i);
	}
	return num;
}

string decimalToBinary(int num) {
	string bs;

	while (num > 0) {
		bs.push_back((num % 2) + '0');
		num /= 2;
	}
	reverse(bs.begin(), bs.end());
	return bs;
}

int main() {
	cin >> s >> f;

	queue<string> q;
	q.push(s);

	for (int time = 0;; time++) {
		int size = q.size();
		if (!size)break;

		while (size--) {
			string cur = q.front(); q.pop();
			if (cur == f) {
				cout << time;
				return 0;
			}

			int num = binaryToDecimal(cur);
			for (int i = 1; i < cur.length(); i++) {
				cur[i] = (!(cur[i] - '0')) + '0';
				if (safe(binaryToDecimal(cur))) {
					q.push(cur); visit[binaryToDecimal(cur)] = true;
				}
				cur[i] = (!(cur[i] - '0')) + '0';
			}
			if (safe(num + 1)) {
				q.push(decimalToBinary(num + 1)); visit[num + 1] = true;
			}
			if (safe(num - 1)) {
				q.push(decimalToBinary(num - 1)); visit[num - 1] = true;
			}

		}
	}


	return 0;
}