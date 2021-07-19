#include <iostream>
#include <string>
using namespace std;
int n,l; string s, pat;
int main() {
	cin >> n;
	cin >> pat;
	l = pat.length(); n--;
	while (n--) {
		cin >> s;
		for (int i = 0; i < l; i++) {
			if (pat[i] == '?')continue;
			if (pat[i] != s[i])pat[i] = '?';
		}
	}
	cout << pat;
	return 0;
}