#include <iostream>
#include <string>
#include <map>
using namespace std;
int n, m, ans;
string s;
map<string, bool> d;
map<string, bool>::iterator it;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		d.insert(make_pair(s, false));
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		it = d.find(s);
		if (it != d.end()) {
			ans++;
			it->second = true;
		}
	}
	cout << ans << '\n';
	for (it = d.begin(); it != d.end(); it++) {
		if (it->second)
			cout << it->first << '\n';
	}
	return 0;
}