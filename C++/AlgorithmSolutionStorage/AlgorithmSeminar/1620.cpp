#include <iostream>
#include <string>
#include <map>
using namespace std;
int n, m;
string s;
map<string, int> m1;
map<int, string> m2;
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		m1.insert(make_pair(s, i));
		m2.insert(make_pair(i, s));
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		int n = atoi(s.c_str());
		if (n)
			cout << m2.find(n)->second << '\n';
		else
			cout << m1.find(s)->second << '\n';
	}
	return 0;
}