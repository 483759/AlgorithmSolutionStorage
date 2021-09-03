#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m;

int main() {
	freopen("input.txt", "r", stdin);
	char str[35];
	int cnt = 0;
	while (scanf(" %[^\n]s", str) != EOF) {
		string s(str); cnt++;
		if (m.find(s) != m.end()) {
			m[s]++;
		}
		else {
			m.insert(make_pair(s, 1));
		}
	}

	cout << fixed;
	cout.precision(4);
	for (auto k : m) {
		cout << k.first <<" "<< (double)(k.second * 100) / cnt << '\n';
	}
	
	return 0;
}